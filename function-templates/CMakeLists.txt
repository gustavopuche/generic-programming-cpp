cmake_minimum_required(VERSION 3.15)
project( function-templates )
# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Threads REQUIRED)
add_executable( function-templates function-templates.cpp )
add_custom_target(run)
add_custom_command( TARGET run
	POST_BUILD COMMAND ./function-templates)
