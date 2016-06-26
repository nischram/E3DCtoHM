#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "RscpProtocol.h"
#include "RscpTags.h"
#include "SocketConnection.h"
#include "AES.h"


#define AES_KEY_SIZE        32
#define AES_BLOCK_SIZE      32
#define SERVER_PORT         5033

static int iSocket = -1;
static int iAuthenticated = 0;
static AES aesEncrypter;
static AES aesDecrypter;
static uint8_t ucEncryptionIV[AES_BLOCK_SIZE];
static uint8_t ucDecryptionIV[AES_BLOCK_SIZE];

char SERVER_IP[32];
char E3DC_USER[32];
char E3DC_PASS[32];
char AES_PASS[32];
char HM_IP[32];
char TAG_EMS_ISE_POWER_PV[5];
char TAG_EMS_ISE_POWER_BAT[5];
char TAG_EMS_ISE_POWER_HOME[5];
char TAG_EMS_ISE_POWER_NET_IN[5];
char TAG_EMS_ISE_POWER_NET_OUT[5];
char TAG_EMS_ISE_POWER_GRID[5];
char TAG_EMS_ISE_POWER_ADD[5];
char TAG_EMS_ISE_POWER_WB_ALL[5];
char TAG_BAT_ISE_SOC[5];
char RSCP_ISE_Time[5];
char SleepTime[3];

int TAG_EMS_OUT_POWER_PV = 0;
int TAG_EMS_OUT_POWER_BAT = 0;
int TAG_EMS_OUT_POWER_HOME = 0;
int TAG_EMS_OUT_POWER_GRID = 0;
int TAG_BAT_OUT_SOC = 0;
int TAG_EMS_OUT_POWER_ADD = 0;
int TAG_EMS_OUT_POWER_WB_ALL = 0;

using namespace std;

void printsend(int id,int value){
    char batch[128];
    memset(batch, 0x00, sizeof(batch));

	// "curl -m1" bedeutet soviel wie Anfrage abschicken aber maximal 1Sekunde auf Antwort warten//
	// "&" am schluss bedeutet im Hintergrund ausführen damit dieses Programm weiter laufen kann //
    snprintf(batch, sizeof(batch), "curl \"http://%s/config/xmlapi/statechange.cgi?ise_id=%i&new_value=%i\" > /dev/null 2>&1",HM_IP , id, value);
    printf("send to Homematic ISE_ID %i new Value = %i\n",id, value);
    system(batch);
}

int createRequestExample(SRscpFrameBuffer * frameBuffer) {
    RscpProtocol protocol;
    SRscpValue rootValue;
    // The root container is create with the TAG ID 0 which is not used by any device.
    protocol.createContainerValue(&rootValue, 0);

    //---------------------------------------------------------------------------------------------------------
    // Create a request frame
    //---------------------------------------------------------------------------------------------------------
    if(iAuthenticated == 0)
    {
        printf("\nRequest authentication\n");
        // authentication request
        SRscpValue authenContainer;
        protocol.createContainerValue(&authenContainer, TAG_RSCP_REQ_AUTHENTICATION);
        protocol.appendValue(&authenContainer, TAG_RSCP_AUTHENTICATION_USER, E3DC_USER);
        protocol.appendValue(&authenContainer, TAG_RSCP_AUTHENTICATION_PASSWORD, E3DC_PASS);
        // append sub-container to root container
        protocol.appendValue(&rootValue, authenContainer);
        // free memory of sub-container as it is now copied to rootValue
        protocol.destroyValueData(authenContainer);
    }
    else
    {
        printf("\nRequest cyclic data\n");
        // request power data information
        protocol.appendValue(&rootValue, TAG_EMS_REQ_POWER_PV);
        protocol.appendValue(&rootValue, TAG_EMS_REQ_POWER_BAT);
        protocol.appendValue(&rootValue, TAG_EMS_REQ_POWER_HOME);
        protocol.appendValue(&rootValue, TAG_EMS_REQ_POWER_GRID);
        int intTAG_EMS_ISE_POWER_ADD = atoi(TAG_EMS_ISE_POWER_ADD);
        if (intTAG_EMS_ISE_POWER_ADD > 0){
          protocol.appendValue(&rootValue, TAG_EMS_REQ_POWER_ADD);
        }
        int intTAG_EMS_ISE_POWER_WB_ALL = atoi(TAG_EMS_ISE_POWER_WB_ALL);
        if (intTAG_EMS_ISE_POWER_WB_ALL > 0){
          protocol.appendValue(&rootValue, TAG_EMS_REQ_POWER_WB_ALL);
        }


        // request battery information
        SRscpValue batteryContainer;
        protocol.createContainerValue(&batteryContainer, TAG_BAT_REQ_DATA);
        protocol.appendValue(&batteryContainer, TAG_BAT_INDEX, (uint8_t)0);
        protocol.appendValue(&batteryContainer, TAG_BAT_REQ_RSOC);
        //protocol.appendValue(&batteryContainer, TAG_BAT_REQ_MODULE_VOLTAGE);
        //protocol.appendValue(&batteryContainer, TAG_BAT_REQ_CURRENT);
        // append sub-container to root container
        protocol.appendValue(&rootValue, batteryContainer);
        // free memory of sub-container as it is now copied to rootValue
        protocol.destroyValueData(batteryContainer);
    }

    // create buffer frame to send data to the S10
    protocol.createFrameAsBuffer(frameBuffer, rootValue.data, rootValue.length, true); // true to calculate CRC on for transfer
    // the root value object should be destroyed after the data is copied into the frameBuffer and is not needed anymore
    protocol.destroyValueData(rootValue);

    return 0;
}

int handleResponseValue(RscpProtocol *protocol, SRscpValue *response) {
    // check if any of the response has the error flag set and react accordingly
    if(response->dataType == RSCP::eTypeError) {
        // handle error for example access denied errors
        uint32_t uiErrorCode = protocol->getValueAsUInt32(response);
        printf("Tag 0x%08X received error code %u.\n", response->tag, uiErrorCode);
        return -1;
    }

    // check the SRscpValue TAG to detect which response it is
    switch(response->tag){
    case TAG_RSCP_AUTHENTICATION: {
        // It is possible to check the response->dataType value to detect correct data type
        // and call the correct function. If data type is known,
        // the correct function can be called directly like in this case.
        uint8_t ucAccessLevel = protocol->getValueAsUChar8(response);
        if(ucAccessLevel > 0) {
            iAuthenticated = 1;
        }
        printf("RSCP authentitication level %i\n", ucAccessLevel);
        break;
    }
    case TAG_EMS_POWER_PV: {    // response for TAG_EMS_REQ_POWER_PV
        int32_t iPower = protocol->getValueAsInt32(response);
        int RSCP_OUT_Time = time(NULL);
        int intRSCP_ISE_Time = atoi(RSCP_ISE_Time);
        printsend(intRSCP_ISE_Time, RSCP_OUT_Time);
        printf("EMS PV power is %i W\n", iPower);
        TAG_EMS_OUT_POWER_PV = iPower;
        int intTAG_EMS_ISE_POWER_PV = atoi(TAG_EMS_ISE_POWER_PV);
        printsend(intTAG_EMS_ISE_POWER_PV, TAG_EMS_OUT_POWER_PV);
        break;
    }
    case TAG_EMS_POWER_BAT: {    // response for TAG_EMS_REQ_POWER_BAT
        int32_t iPower = protocol->getValueAsInt32(response);
        printf("EMS BAT power is %i W\n", iPower);
        TAG_EMS_OUT_POWER_BAT = iPower;
        int intTAG_EMS_ISE_POWER_BAT = atoi(TAG_EMS_ISE_POWER_BAT);
        printsend(intTAG_EMS_ISE_POWER_BAT, TAG_EMS_OUT_POWER_BAT);
        break;
    }
    case TAG_EMS_POWER_HOME: {    // response for TAG_EMS_REQ_POWER_HOME
        int32_t iPower = protocol->getValueAsInt32(response);
        printf("EMS house power is %i W\n", iPower);
        TAG_EMS_OUT_POWER_HOME = iPower;
        int intTAG_EMS_ISE_POWER_HOME = atoi(TAG_EMS_ISE_POWER_HOME);
        printsend(intTAG_EMS_ISE_POWER_HOME, TAG_EMS_OUT_POWER_HOME);
        break;
    }
    case TAG_EMS_POWER_GRID: {    // response for TAG_EMS_REQ_POWER_GRID
        int32_t iPower = protocol->getValueAsInt32(response);
        printf("EMS grid power is %i W\n", iPower);
        TAG_EMS_OUT_POWER_GRID = iPower;
        int intTAG_EMS_ISE_POWER_GRID = atoi(TAG_EMS_ISE_POWER_GRID);
        printsend(intTAG_EMS_ISE_POWER_GRID, TAG_EMS_OUT_POWER_GRID);
        if(iPower >= 0) {
            int TAG_EMS_OUT_POWER_NET_IN = 0;
            int TAG_EMS_OUT_POWER_NET_OUT = iPower;
            int intTAG_EMS_ISE_POWER_NET_IN = atoi(TAG_EMS_ISE_POWER_NET_IN);
            printsend(intTAG_EMS_ISE_POWER_NET_IN, TAG_EMS_OUT_POWER_NET_IN);
            int intTAG_EMS_ISE_POWER_NET_OUT = atoi(TAG_EMS_ISE_POWER_NET_OUT);
            printsend(intTAG_EMS_ISE_POWER_NET_OUT, TAG_EMS_OUT_POWER_NET_OUT);
        }
        else {
          int neg_GRID = (iPower * -1);
          int TAG_EMS_OUT_POWER_NET_IN = neg_GRID;
          int TAG_EMS_OUT_POWER_NET_OUT = 0;
          int intTAG_EMS_ISE_POWER_NET_IN = atoi(TAG_EMS_ISE_POWER_NET_IN);
          printsend(intTAG_EMS_ISE_POWER_NET_IN, TAG_EMS_OUT_POWER_NET_IN);
          int intTAG_EMS_ISE_POWER_NET_OUT = atoi(TAG_EMS_ISE_POWER_NET_OUT);
          printsend(intTAG_EMS_ISE_POWER_NET_OUT, TAG_EMS_OUT_POWER_NET_OUT);
        }
        break;
    }
    case TAG_EMS_POWER_ADD: {    // response for TAG_EMS_REQ_POWER_ADD
        int32_t iPower = protocol->getValueAsInt32(response);
        printf("EMS add power meter power is %i W\n", iPower);
        TAG_EMS_OUT_POWER_ADD = iPower;
        int intTAG_EMS_ISE_POWER_ADD = atoi(TAG_EMS_ISE_POWER_ADD);
        printsend(intTAG_EMS_ISE_POWER_ADD, TAG_EMS_OUT_POWER_ADD);
        break;
    }
    case TAG_EMS_POWER_WB_ALL: {    // response for TAG_EMS_REQ_POWER_WB_ALL
        int32_t iPower = protocol->getValueAsInt32(response);
        printf("EMS WB power meter power is %i W\n", iPower);
        TAG_EMS_OUT_POWER_WB_ALL = iPower;
        int intTAG_EMS_ISE_POWER_WB_ALL = atoi(TAG_EMS_ISE_POWER_WB_ALL);
        printsend(intTAG_EMS_ISE_POWER_WB_ALL, TAG_EMS_OUT_POWER_WB_ALL);
        break;
    }
    case TAG_BAT_DATA: {        // resposne for TAG_BAT_REQ_DATA
        uint8_t ucBatteryIndex = 0;
        std::vector<SRscpValue> batteryData = protocol->getValueAsContainer(response);
        for(size_t i = 0; i < batteryData.size(); ++i) {
            if(batteryData[i].dataType == RSCP::eTypeError) {
                // handle error for example access denied errors
                uint32_t uiErrorCode = protocol->getValueAsUInt32(&batteryData[i]);
                printf("Tag 0x%08X received error code %u.\n", batteryData[i].tag, uiErrorCode);
                return -1;
            }
            // check each battery sub tag
            switch(batteryData[i].tag) {
            case TAG_BAT_INDEX: {
                ucBatteryIndex = protocol->getValueAsUChar8(&batteryData[i]);
                break;
            }
            case TAG_BAT_RSOC: {              // response for TAG_BAT_REQ_RSOC
                float fSOC = protocol->getValueAsFloat32(&batteryData[i]);
                printf("Battery SOC is %0.1f %%\n", fSOC);
                TAG_BAT_OUT_SOC  = fSOC;
                int intTAG_BAT_ISE_SOC = atoi(TAG_BAT_ISE_SOC);
                printsend(intTAG_BAT_ISE_SOC, TAG_BAT_OUT_SOC);
                break;
            }
            case TAG_BAT_MODULE_VOLTAGE: {    // response for TAG_BAT_REQ_MODULE_VOLTAGE
                float fVoltage = protocol->getValueAsFloat32(&batteryData[i]);
                printf("Battery total voltage is %0.1f V\n", fVoltage);
                break;
            }
            case TAG_BAT_CURRENT: {    // response for TAG_BAT_REQ_CURRENT
                float fVoltage = protocol->getValueAsFloat32(&batteryData[i]);
                printf("Battery current is %0.1f A\n", fVoltage);
                break;
            }
            // ...
            default:
                // default behaviour
                printf("Unknown battery tag %08X\n", response->tag);
                break;
            }
        }
        protocol->destroyValueData(batteryData);
        break;
    }
    // ...
    default:
        // default behavior
        printf("Unknown tag %08X\n", response->tag);
        break;
    }
}
static int processReceiveBuffer(const unsigned char * ucBuffer, int iLength)
{
    RscpProtocol protocol;
    SRscpFrame frame;

    int iResult = protocol.parseFrame(ucBuffer, iLength, &frame);
    if(iResult < 0) {
        // check if frame length error occured
        // in that case the full frame length was not received yet
        // and the receive function must get more data
        if(iResult == RSCP::ERR_INVALID_FRAME_LENGTH) {
            return 0;
        }
        // otherwise a not recoverable error occured and the connection can be closed
        else {
            return iResult;
        }
    }

    int iProcessedBytes = iResult;

    // process each SRscpValue struct seperately
    for(unsigned int i; i < frame.data.size(); i++) {
        handleResponseValue(&protocol, &frame.data[i]);
    }

    // destroy frame data and free memory
    protocol.destroyFrameData(frame);

    // returned processed amount of bytes
    return iProcessedBytes;
}

static void receiveLoop(bool & bStopExecution)
{
    //--------------------------------------------------------------------------------------------------------------
    // RSCP Receive Frame Block Data
    //--------------------------------------------------------------------------------------------------------------
    // setup a static dynamic buffer which is dynamically expanded (re-allocated) on demand
    // the data inside this buffer is not released when this function is left
    static int iReceivedBytes = 0;
    static std::vector<uint8_t> vecDynamicBuffer;

    // check how many RSCP frames are received, must be at least 1
    // multiple frames can only occur in this example if one or more frames are received with a big time delay
    // this should usually not occur but handling this is shown in this example
    int iReceivedRscpFrames = 0;
    while(!bStopExecution && ((iReceivedBytes > 0) || iReceivedRscpFrames == 0))
    {
        // check and expand buffer
        if((vecDynamicBuffer.size() - iReceivedBytes) < 4096) {
            // check maximum size
            if(vecDynamicBuffer.size() > RSCP_MAX_FRAME_LENGTH) {
                // something went wrong and the size is more than possible by the RSCP protocol
                printf("Maximum buffer size exceeded %i\n", vecDynamicBuffer.size());
                bStopExecution = true;
                break;
            }
            // increase buffer size by 4096 bytes each time the remaining size is smaller than 4096
            vecDynamicBuffer.resize(vecDynamicBuffer.size() + 4096);
        }
        // receive data
        int iResult = SocketRecvData(iSocket, &vecDynamicBuffer[0] + iReceivedBytes, vecDynamicBuffer.size() - iReceivedBytes);
        if(iResult < 0)
        {
            // check errno for the error code to detect if this is a timeout or a socket error
            if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) {
                // receive timed out -> continue with re-sending the initial block
                printf("Response receive timeout (retry)\n");
                break;
            }
            // socket error -> check errno for failure code if needed
            printf("Socket receive error. errno %i\n", errno);
            bStopExecution = true;
            break;
        }
        else if(iResult == 0)
        {
            // connection was closed regularly by peer
            // if this happens on startup each time the possible reason is
            // wrong AES password or wrong network subnet (adapt hosts.allow file required)
            printf("Connection closed by peer\n");
            bStopExecution = true;
            break;
        }
        // increment amount of received bytes
        iReceivedBytes += iResult;

        // process all received frames
        while (!bStopExecution)
        {
            // round down to a multiple of AES_BLOCK_SIZE
            int iLength = ROUNDDOWN(iReceivedBytes, AES_BLOCK_SIZE);
            // if not even 32 bytes were received then the frame is still incomplete
            if(iLength == 0) {
                break;
            }
            // resize temporary decryption buffer
            std::vector<uint8_t> decryptionBuffer;
            decryptionBuffer.resize(iLength);
            // initialize encryption sequence IV value with value of previous block
            aesDecrypter.SetIV(ucDecryptionIV, AES_BLOCK_SIZE);
            // decrypt data from vecDynamicBuffer to temporary decryptionBuffer
            aesDecrypter.Decrypt(&vecDynamicBuffer[0], &decryptionBuffer[0], iLength / AES_BLOCK_SIZE);

            // data was received, check if we received all data
            int iProcessedBytes = processReceiveBuffer(&decryptionBuffer[0], iLength);
            if(iProcessedBytes < 0) {
                // an error occured;
                printf("Error parsing RSCP frame: %i\n", iProcessedBytes);
                // stop execution as the data received is not RSCP data
                bStopExecution = true;
                break;

            }
            else if(iProcessedBytes > 0) {
                // round up the processed bytes as iProcessedBytes does not include the zero padding bytes
                iProcessedBytes = ROUNDUP(iProcessedBytes, AES_BLOCK_SIZE);
                // store the IV value from encrypted buffer for next block decryption
                memcpy(ucDecryptionIV, &vecDynamicBuffer[0] + iProcessedBytes - AES_BLOCK_SIZE, AES_BLOCK_SIZE);
                // move the encrypted data behind the current frame data (if any received) to the front
                memcpy(&vecDynamicBuffer[0], &vecDynamicBuffer[0] + iProcessedBytes, vecDynamicBuffer.size() - iProcessedBytes);
                // decrement the total received bytes by the amount of processed bytes
                iReceivedBytes -= iProcessedBytes;
                // increment a counter that a valid frame was received and
                // continue parsing process in case a 2nd valid frame is in the buffer as well
                iReceivedRscpFrames++;
            }
            else {
                // iProcessedBytes is 0
                // not enough data of the next frame received, go back to receive mode if iReceivedRscpFrames == 0
                // or transmit mode if iReceivedRscpFrames > 0
                break;
            }
        }
    }
}

static void mainLoop(void)
{
    RscpProtocol protocol;
    bool bStopExecution = false;

    while(!bStopExecution)
    {
        //--------------------------------------------------------------------------------------------------------------
        // RSCP Transmit Frame Block Data
        //--------------------------------------------------------------------------------------------------------------
        SRscpFrameBuffer frameBuffer;
        memset(&frameBuffer, 0, sizeof(frameBuffer));

        // create an RSCP frame with requests to some example data
        createRequestExample(&frameBuffer);

        // check that frame data was created
        if(frameBuffer.dataLength > 0)
        {
            // resize temporary encryption buffer to a multiple of AES_BLOCK_SIZE
            std::vector<uint8_t> encryptionBuffer;
            encryptionBuffer.resize(ROUNDUP(frameBuffer.dataLength, AES_BLOCK_SIZE));
            // zero padding for data above the desired length
            memset(&encryptionBuffer[0] + frameBuffer.dataLength, 0, encryptionBuffer.size() - frameBuffer.dataLength);
            // copy desired data length
            memcpy(&encryptionBuffer[0], frameBuffer.data, frameBuffer.dataLength);
            // set continues encryption IV
            aesEncrypter.SetIV(ucEncryptionIV, AES_BLOCK_SIZE);
            // start encryption from encryptionBuffer to encryptionBuffer, blocks = encryptionBuffer.size() / AES_BLOCK_SIZE
            aesEncrypter.Encrypt(&encryptionBuffer[0], &encryptionBuffer[0], encryptionBuffer.size() / AES_BLOCK_SIZE);
            // save new IV for next encryption block
            memcpy(ucEncryptionIV, &encryptionBuffer[0] + encryptionBuffer.size() - AES_BLOCK_SIZE, AES_BLOCK_SIZE);

            // send data on socket
            int iResult = SocketSendData(iSocket, &encryptionBuffer[0], encryptionBuffer.size());
            if(iResult < 0) {
                printf("Socket send error %i. errno %i\n", iResult, errno);
                bStopExecution = true;
            }
            else {
                // go into receive loop and wait for response
                receiveLoop(bStopExecution);
            }
        }
        // free frame buffer memory
        protocol.destroyFrameData(&frameBuffer);

        // main loop sleep / cycle time before next request
        int intSleepTime = atoi(SleepTime);
        printf("Sleep %i seconds\n",intSleepTime);
        sleep(intSleepTime);
    }
}

int main()
{

  fstream datei("parameters.txt",ios::in);
  if (datei.is_open()) {
  datei.getline(SERVER_IP,32, ';');
  datei.getline(E3DC_USER,32, ';');
  datei.getline(E3DC_PASS,32, ';');
  datei.getline(AES_PASS,32, ';');
  datei.getline(HM_IP,32, ';');
  datei.getline(TAG_EMS_ISE_POWER_PV,6, ';');
  datei.getline(TAG_EMS_ISE_POWER_BAT,6, ';');
  datei.getline(TAG_EMS_ISE_POWER_HOME,6, ';');
  datei.getline(TAG_EMS_ISE_POWER_NET_IN,6, ';');
  datei.getline(TAG_EMS_ISE_POWER_NET_OUT,6, ';');
  datei.getline(TAG_EMS_ISE_POWER_GRID,6, ';');
  datei.getline(TAG_EMS_ISE_POWER_ADD,6, ';');
  datei.getline(TAG_EMS_ISE_POWER_WB_ALL,6, ';');
  datei.getline(TAG_BAT_ISE_SOC,6, ';');
  datei.getline(RSCP_ISE_Time,6, ';');
  datei.getline(SleepTime,4, ';');
  datei.close();
  std::printf("SERVER_IP:\t%-10s\n",SERVER_IP);
  std::printf("E3DC_USER:\t%-10s\n",E3DC_USER);
  std::printf("E3DC_PASS:\t%-10s\n",E3DC_PASS);
  std::printf("AES_PASS:\t%-10s\n",AES_PASS);
  std::printf("HM_IP:\t%-10s\n",HM_IP);
  std::printf("TAG_EMS_ISE_POWER_PV:\t%-10s\n",TAG_EMS_ISE_POWER_PV);
  std::printf("TAG_EMS_ISE_POWER_BAT:\t%-10s\n",TAG_EMS_ISE_POWER_BAT);
  std::printf("TAG_EMS_ISE_POWER_HOME:\t%-10s\n",TAG_EMS_ISE_POWER_HOME);
  std::printf("TAG_EMS_ISE_POWER_NET_IN:\t%-10s\n",TAG_EMS_ISE_POWER_NET_IN);
  std::printf("TAG_EMS_ISE_POWER_NET_OUT:\t%-10s\n",TAG_EMS_ISE_POWER_NET_OUT);
  std::printf("TAG_EMS_ISE_POWER_GRID:\t%-10s\n",TAG_EMS_ISE_POWER_GRID);
  std::printf("TAG_EMS_ISE_POWER_ADD:\t%-10s\n",TAG_EMS_ISE_POWER_ADD);
  std::printf("TAG_EMS_ISE_POWER_WB_ALL:\t%-10s\n",TAG_EMS_ISE_POWER_WB_ALL);
  std::printf("TAG_BAT_ISE_SOC:\t%-10s\n",TAG_BAT_ISE_SOC);
  std::printf("RSCP_ISE_Time:\t%-10s\n",RSCP_ISE_Time);
  std::printf("SleepTime:\t%-10s\n",SleepTime);
 }
 else cerr << "Konnte Datei nicht oeffnen\n"; // Fehlerfall

    // endless application which re-connections to server on connection lost
    while(true){


        // connect to server
        printf("Connecting to server %s:%i\n", SERVER_IP, SERVER_PORT);
        iSocket = SocketConnect(SERVER_IP, SERVER_PORT);
        if(iSocket < 0) {
            printf("Connection failed\n");
            sleep(1);
            continue;
        }
        printf("Connected successfully\n");

        // reset authentication flag
        iAuthenticated = 0;

        // create AES key and set AES parameters
        {
            // initialize AES encryptor and decryptor IV
            memset(ucDecryptionIV, 0xff, AES_BLOCK_SIZE);
            memset(ucEncryptionIV, 0xff, AES_BLOCK_SIZE);

            // limit password length to AES_KEY_SIZE
            int iPasswordLength = strlen(AES_PASS);
            if(iPasswordLength > AES_KEY_SIZE)
                iPasswordLength = AES_KEY_SIZE;

            // copy up to 32 bytes of AES key password
            uint8_t ucAesKey[AES_KEY_SIZE];
            memset(ucAesKey, 0xff, AES_KEY_SIZE);
            memcpy(ucAesKey, AES_PASS, iPasswordLength);

            // set encryptor and decryptor parameters
            aesDecrypter.SetParameters(AES_KEY_SIZE * 8, AES_BLOCK_SIZE * 8);
            aesEncrypter.SetParameters(AES_KEY_SIZE * 8, AES_BLOCK_SIZE * 8);
            aesDecrypter.StartDecryption(ucAesKey);
            aesEncrypter.StartEncryption(ucAesKey);
        }

        // enter the main transmit / receive loop
        mainLoop();

        // close socket connection
        SocketClose(iSocket);
        iSocket = -1;
    }

    return 0;
}
