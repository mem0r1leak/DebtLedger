cmake_minimum_required(VERSION 3.10)

project(DebtLedger)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(DebtLedger
        server/main.cpp
        core/models.h
        core/providers/ShoppingHistoryProvider.cpp)

target_link_libraries(DebtLedger PRIVATE Threads::Threads)

set_target_properties(DebtLedger PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")