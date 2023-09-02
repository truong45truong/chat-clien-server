SRC_SERVER = ../../src/server/server.h ../../src/server/server.cpp ../../src/server/main_server.cpp
SRC_LOGGING = ../../include/logging/logging.h ../../include/logging/logging.cpp
build-server:
	g++ $(SRC_SERVER) $(SRC_LOGGING) -o server.exe
run-server:
	./server.exe
.PHONY: build-server run-server