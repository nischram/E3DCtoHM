CXX=g++
ROOT_VALUE=/home/pi/e3dc-rscp/InstallParameter
ROOT_VALUE2=/home/pi/e3dc-rscp/e3dc-rscp
ROOT_VALUE3=/home/pi/e3dc-rscp/watchdogHM

all: $(ROOT_VALUE) $(ROOT_VALUE2) $(ROOT_VALUE3)

$(ROOT_VALUE): clean
	$(CXX) -O1 InstallParam.cpp -o $@
$(ROOT_VALUE2): clean
	$(CXX) -O3 RscpHomeMatic.cpp RscpProtocol.cpp AES.cpp SocketConnection.cpp -o $@
$(ROOT_VALUE3): clean
	$(CXX) -O1 WatchdogHM.cpp -o $@


clean:
	-rm $(ROOT_VALUE) $(ROOT_VALUE2) $(ROOT_VALUE3) $(VECTOR)
