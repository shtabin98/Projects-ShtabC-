cmake_minimum_required(VERSION 3.22.0)

project(Racing-exe 
	VERSION 0.1
	DESCRIPTION "Racing executable" 
	LANGUAGES CXX)
	
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB bin-src "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(race_sim ${bin-src})
	
target_link_libraries (race_sim PRIVATE race_lib)

target_include_directories (race_sim
	PRIVATE 
		${CMAKE_CURRENT_SOURCE_DIR}/include
		${CMAKE_SOURCE_DIR}/lib/include)