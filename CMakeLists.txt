cmake_minimum_required(VERSION 3.20)
project(ScreenCast CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Shared network protocol definitions
add_subdirectory(common)

# Build host on Windows, client on Linux
if(WIN32)
    message(STATUS "Configuring Windows Host Build...")
    add_subdirectory(host)
elseif(UNIX AND NOT APPLE)
    message(STATUS "Configuring Linux Client Build...")
    add_subdirectory(client)
endif()