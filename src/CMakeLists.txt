cmake_minimum_required(VERSION 3.7)

find_package( spdlog REQUIRED )
find_package( PostgreSQL REQUIRED )

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")
set(PQXX ../libpqxx)
find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

add_executable( main main.m.cpp postgres_accessor.cpp )

target_include_directories( main PRIVATE ${PostgreSQL_INCLUDE_DIRS} )
target_link_libraries( main PRIVATE ${PostgreSQL_LIBRARIES}
                                    spdlog::spdlog
                                    ${PQXX_LIB}
                                    ${PQ_LIB} )