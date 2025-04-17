cmake_minimum_required(VERSION 3.16)
project(Producer-Consumer VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
    etl
    GIT_REPOSITORY https://github.com/ETLCPP/etl
    GIT_TAG        20.40.0
)
FetchContent_MakeAvailable(etl)


# Print paths for debugging
message(STATUS "ETL include path: ${etl_SOURCE_DIR}/include")

add_executable(program
    source/packetbuffer.cpp
    source/receiver.cpp
    source/transmitter.cpp
    source/main.cpp
)
target_include_directories(program PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${etl_SOURCE_DIR}/include  # Add ETL's include path
)

target_link_libraries(program
    etl::etl
)