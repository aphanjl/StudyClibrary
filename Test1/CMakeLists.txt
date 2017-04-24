cmake_minimum_required( VERSION 2.6 )
project( Test1 )
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTSON)

set(LOOP_DIRS 
	"${PROJECT_SOURCE_DIR}/TestClibrary"
	"${PROJECT_SOURCE_DIR}/TestAlgorithm"
	"${PROJECT_SOURCE_DIR}/TestFramework")

include_directories("${PROJECT_SOURCE_DIR}/TestCommon")

foreach(dir ${LOOP_DIRS})
include_directories( ${dir} )
SUBDIRS(${dir})
endforeach(dir)

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
link_directories(${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")
else()
link_directories(${PROJECT_SOURCE_DIR}/sharedlib)
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/sharedbin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/sharedlib")
endif()

add_executable( Test1 main.cpp )
target_link_libraries(Test1 TestLoop TestClass TestFramework)