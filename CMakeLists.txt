cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME lr2)
project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX) # OR C

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

file(GLOB_RECURSE SOURCE_FILES src/*)
file(GLOB_RECURSE SOURCE_HEADERS include/*)
set(SOURCES ${SOURCE_FILES} ${SOURCE_HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include/)
