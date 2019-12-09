cmake_minimum_required(VERSION 3.7)

project(main CXX C)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory( "libpqxx" )
add_subdirectory( "src" )

#enable_testing()

