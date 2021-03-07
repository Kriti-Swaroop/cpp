cmake_minimum_required(VERSION 3.18)

set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "")
set(APP_VERSION "1.0.0" CACHE STRING "Application Version" FORCE)
project(Guess VERSION ${APP_VERSION})

add_executable(${PROJECT_NAME} "./src/Guess.cpp")
