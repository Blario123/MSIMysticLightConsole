cmake_minimum_required(VERSION 3.17)
project(MSIMysticLightConsole)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(MSIMysticLightConsole
        src/MSIMysticLightControl.cpp
        src/MSIMysticLightControl.h
        src/terminal.cpp
        src/terminal.h
        src/log.cpp
        src/log.h
        src/stdafx.cpp
        src/stdafx.h
        src/targetver.h
        include/MysticLight/MysticLight_SDK.h
        )