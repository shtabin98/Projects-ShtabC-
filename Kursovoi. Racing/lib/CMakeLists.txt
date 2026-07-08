cmake_minimum_required(VERSION 3.22.0)

project(Racing-lib 
	VERSION 0.1
	DESCRIPTION "Racing-lib" 
	LANGUAGES CXX)

file(GLOB lib-src "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(race_lib SHARED ${lib-src})
	
target_include_directories (race_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(race_lib PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS ON
)