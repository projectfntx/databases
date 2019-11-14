cmake_minimum_required(VERSION 3.15.5)

find_package( spdlog REQUIRED )

add_executable( main main.m.cpp )
target_link_libraries( main PRIVATE spdlog::spdlog )
