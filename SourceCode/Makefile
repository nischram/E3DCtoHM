CXX=g++
ROOT_VALUE=e3dc-rscp

all: $(ROOT_VALUE)

$(ROOT_VALUE): clean
	$(CXX) -O3 RscpHomeMatic.cpp RscpProtocol.cpp AES.cpp SocketConnection.cpp -o $@


clean:
	-rm $(ROOT_VALUE) $(VECTOR)
