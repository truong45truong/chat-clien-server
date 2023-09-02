
SRC_CLIENT = ../../src/client/client.h ../../src/client/client.cpp ../../src/client/main_client.cpp
SRC_UI_CLIENT = ../../src/client/ui_console.h ../../src/client/ui_console.cpp 
SRC_BASE = ../../src/base/constants/message_code.cpp
build-client:
	g++ $(SRC_CLIENT) $(SRC_UI_CLIENT) $(SRC_BASE) -o client.exe
run-client:
	./client.exe

.PHONY: build-client run-client