cmake_minimum_required(VERSION 3.22.0)

project(Racing 
	VERSION 0.1
	DESCRIPTION "..." 
	LANGUAGES CXX)
	
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пути вывода, чтобы exe и dll лежали рядом
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(lib)
add_subdirectory(bin)