# CMakeLists for component lib
cmake_minimum_required(VERSION 3.5)

project(gwcomponent)

SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_PROCESSOR arm) 
SET(TOOLCHAIN_DIR "/home/dpdk/liqing/petalinux/gcc-arm-linux-gnueabi")
SET(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_DIR})
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

SET(CMAKE_C_COMPILER ${TOOLCHAIN_DIR}/bin/arm-linux-gnueabihf-gcc-6.2.1)
SET(CMAKE_CXX_COMPILER ${TOOLCHAIN_DIR}/bin/arm-linux-gnueabihf-g++)

# zlog
link_directories("/home/dpdk/liqing/common/lib/")
include_directories("/home/dpdk/liqing/common/include/")

# source file
file(GLOB_RECURSE SOURCE_FILES_1 "gw_msg_queue/*.c")
file(GLOB_RECURSE SOURCE_FILES_2 "gw_threadpool/*.c")
file(GLOB_RECURSE SOURCE_FILES_3 "gw_timer/*.c")

message(STATUS "PROJECT_SOURCE_DIR": ${PROJECT_SOURCE_DIR})

include_directories("${PROJECT_SOURCE_DIR}/gw_msg_queue")
include_directories("${PROJECT_SOURCE_DIR}/gw_threadpool")
include_directories("${PROJECT_SOURCE_DIR}/gw_timer")
include_directories("${PROJECT_SOURCE_DIR}/include")
link_directories("${PROJECT_SOURCE_DIR}/lib")

SET(LIB_NAME gwcomponent)

add_library(${LIB_NAME} SHARED ${SOURCE_FILES_1} ${SOURCE_FILES_2} ${SOURCE_FILES_3})

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)


target_link_libraries(${LIB_NAME} cjson)
target_link_libraries(${LIB_NAME} -pthread)
target_link_libraries(${LIB_NAME} -lzlog)

install(FILES ${PROJECT_SOURCE_DIR}/gw_msg_queue/msg_queue.h ${PROJECT_SOURCE_DIR}/gw_msg_queue/priorityQueue.h 
              ${PROJECT_SOURCE_DIR}/gw_threadpool/ThreadPool.h ${PROJECT_SOURCE_DIR}/gw_threadpool/SimpleQueue.h
              ${PROJECT_SOURCE_DIR}/gw_timer/event_timer.h ${PROJECT_SOURCE_DIR}/gw_timer/rbtree.h
              DESTINATION ${PROJECT_SOURCE_DIR}/include/)








