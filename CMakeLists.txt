cmake_minimum_required(VERSION 3.0)

project(chat_client_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_BASE
        ../src/base/constants/message_code.cpp
)

set(SOURCES_CLIENT
        ../src/client/client.cpp
        ../src/client/ui_console.cpp
        ../src/client/ui_console.h
        ../src/client/main_client.cpp
        ../src/client/client.h
        tests/test1.cpp
        tests/test1.cpp
		include/socket/socket.cpp
		include/socket/socket.h
		include/socket/TCPSocket.cpp
		include/socket/TCPSocket.h
		include/socket/constants.h
		include/custom_code/custom_macros.h
)

set(SOURCES_SERVER
        ../src/server/server.h
        ../src/server/server.cpp
        ../src/server/main_server.cpp
        ../include/logging/logging.h
        ../include/logging/logging.cpp
		include/custom_code/custom_macros.h
)

include_directories(
        ../include
        # Add more include directories here as needed
)

# Add an executable for the client
add_executable(client ${SOURCES_CLIENT}  ${SOURCES_BASE})

# Add an executable for the server
add_executable(server ${SOURCES_SERVER} ${SOURCES_BASE})
set(SOURCE_UNIT_TEST
    	tests/test1.cpp
)
add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(project_unit_test ${SOURCE_UNIT_TEST})
target_link_libraries(project_unit_test gtest gtest_main)
