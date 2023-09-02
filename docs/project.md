# Project Info:

-   Project client server does  are connect users together for messaging.
    Also provides gpt chat service to answer questions
-   User can registration, then enter information details.
-   Console UI features

# How it works:

## I. User
1. User create public room
2. User created room can be delete room
3. User select show all room chat opened 
4. User select room do chat
5. User select feature chat gpt 
6. Affter user asking questions server response stream answer

## II. Server
1. Log and save the main operation info,error or warning
2. Login authentication
3. Respond to client requests using a socket connection

## Structure of project:
```
|--- project
    |--- build                      <---- Build project app: server and client:
    |    |--- client
    |    |    |--- client.exe           |---- File exe after build client app 
    |    |    |--- Makefile             |---- Makefile automating building client app
    |    |--- server
    |         |--- server.exe           |---- File exe after build server app 
    |         |--- Makefile             |---- Makefile automating building server app
    |--- data                       <---- File media for project
    |--- docs                       <---- Folder project introduction documents:
    |    |--- install.md                |---- Install the text instructions and run the project
    |    |--- project.md                |---- Introducing the project and work
    |--- examples                   <---- Code exmaples
    |--- external                   <---- External library
    |    |--- googletest                |---- Library use unit test
    |--- extras                     <---- Report file and project related document link
    |--- include                    <---- Code library used
    |    |--- logging                   |---- Log Info, Error, Warning in server 
    |--- libs
    |--- src                        <---- The application's C++ source code
    |    |--- base                      |---- Contains shared code and service 
    |    |    |--- common
    |    |    |--- constants    
    |    |         |--- message_code.cpp    |---- Messages string segment
    |    |--- client                    |---- Code client app
    |    |    |--- client.cpp
    |    |    |--- client.h   
    |    |    |--- ui_console.h
    |    |    |--- ui_console.cpp
    |    |    |--- main_client.cpp          |---- Code main client app
    |    |--- server                    |---- Code server app
    |    |    |--- server.h
    |    |    |--- server.cpp
    |    |    |--- main_server.cpp          |---- Code main client app
    |--- tests                      <---- code unit tests
    |--- tools
    |--- CMakeList.txt               