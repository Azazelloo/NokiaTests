cmake_minimum_required(VERSION 3.5)

project(NokiaTests)

set(SOURCES
		main.cpp
)

set(HEADERS
		Header.h
)

add_executable(Main ${SOURCES} ${HEADERS})

set_target_properties(
		Main PROPERTIES
		CXX_STANDARD 14
		CXX_STANDARD_REQUIRED ON
)