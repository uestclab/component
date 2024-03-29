cmake_minimum_required(VERSION 3.5)

option(var_platform "This is a default option for ARM64 PLATFORM" OFF)
message(STATUS "build public platform switch:"${var_platform})
project(cjson)


if(${var_platform} STREQUAL "ON")
    message(STATUS "start to build ARM platform.")
	# cross complie
	SET(CMAKE_SYSTEM_NAME Linux)
	SET(CMAKE_SYSTEM_PROCESSOR arm) 
	SET(TOOLCHAIN_DIR "/home/dpdk/liqing/petalinux/gcc-arm-linux-gnueabi")
	SET(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_DIR})
	SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
	SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
	SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

	SET(CMAKE_C_COMPILER ${TOOLCHAIN_DIR}/bin/arm-linux-gnueabihf-gcc-6.2.1)
	SET(CMAKE_CXX_COMPILER ${TOOLCHAIN_DIR}/bin/arm-linux-gnueabihf-g++)
	# cross complie
elseif(${var_platform} STREQUAL "OFF")	
    message(STATUS "start to build ARM64 platform.")
    SET(CMAKE_SYSTEM_NAME Linux)
    SET(CMAKE_SYSTEM_PROCESSOR arm) 
    SET(TOOLCHAIN_DIR "/home/dpdk/liqing/petalinux/petalinux-2018-2/tools/linux-i386/aarch64-linux-gnu")
    SET(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_DIR})
    SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

    SET(CMAKE_C_COMPILER ${TOOLCHAIN_DIR}/bin/aarch64-linux-gnu-gcc-7.2.1)
    SET(CMAKE_CXX_COMPILER ${TOOLCHAIN_DIR}/bin/aarch64-linux-gnu-g++)

endif(${var_platform} STREQUAL "ON")

SET(CMAKE_BUILD_TYPE "Debug")  
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")  
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
SET(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/..")


SET(LIB_NAME cjson)
SET(CMAKE_VERBOSE_MAKEFILE ON)    
SET(ROOT_PATH ".")  

SET(ALL_LIBRARY_SRCS cJSON.c)

add_library(${LIB_NAME} SHARED ${ALL_LIBRARY_SRCS})

#target_link_libraries(${LIB_NAME} -lm)


if(${var_platform} STREQUAL "ON")
    message(STATUS "start to install ARM platform library.")
	install(TARGETS ${LIB_NAME} LIBRARY DESTINATION lib_arm/)
elseif(${var_platform} STREQUAL "OFF")
    message(STATUS "start to build ARM64 platform library.")
	install(TARGETS ${LIB_NAME} LIBRARY DESTINATION lib_arm64/)
endif(${var_platform} STREQUAL "ON")

install(FILES ${PROJECT_SOURCE_DIR}/cJSON.h DESTINATION include/)


