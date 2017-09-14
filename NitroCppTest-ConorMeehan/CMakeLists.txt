cmake_minimum_required(VERSION 3.1)

#################################
# Json library
#################################

set(JSON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/json)
add_library(Json INTERFACE)
target_include_directories(Json INTERFACE ${JSON_INCLUDE_DIR})

#################################
# Main sources as a library. Enables building the tests
# without building the project twice.
#################################

project (NitroCppTest)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

include_directories(include)

file(GLOB NCT_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB NCT_HEADERS ${PROJECT_SOURCE_DIR}/include/*.hpp)

add_library(NitroCppTest_Lib ${NCT_SOURCES} ${NCT_HEADERS})
target_link_libraries(NitroCppTest_Lib Json)

#################################
# Main executable
#################################

include_directories(include)

add_executable(NitroCppTest_Main NitroCppTest.cpp)
target_link_libraries(NitroCppTest_Main NitroCppTest_Lib Json)

#################################
# Testing
#################################
option(NCT_BUILD_TESTS "Should the tests be built" ON)
if(NCT_BUILD_TESTS)
	# Prepare "Catch" library for other executables
	set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/catch)
	add_library(Catch INTERFACE) 
	target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})
	
	file(GLOB TEST_SOURCES ${PROJECT_SOURCE_DIR}/test/*.cpp)

	# Make test executable
	add_executable(NitroCppTest_Tests ${TEST_SOURCES})
	target_link_libraries(NitroCppTest_Tests NitroCppTest_Lib Catch Json)

endif()