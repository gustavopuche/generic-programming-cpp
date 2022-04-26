cmake_minimum_required(VERSION 3.15)
project( value-template-args )
# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Threads REQUIRED)
add_executable( value-template-args value-template-args.cpp )
add_custom_target(run)
add_custom_command( TARGET run
	POST_BUILD COMMAND ./value-template-args)
