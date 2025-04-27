CMAKE_MINIMUM_REQUIRED(VERSION 3.31.6)

PROJECT(Cursework2025-16)


SET(CMAKE_CXX_STANDARD 23)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}/List
    ${CMAKE_CURRENT_SOURCE_DIR}/Database
    ${CMAKE_CURRENT_SOURCE_DIR}/Filer
    ${CMAKE_CURRENT_SOURCE_DIR}/Professor
    ${CMAKE_CURRENT_SOURCE_DIR}/Interface
)

ADD_EXECUTABLE(
    Program src/main.cxx
    Database/Database.cxx
    Filer/Filer.cxx
    Professor/Professor.cxx
    Interface/Interface.cxx
)
