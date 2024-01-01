cmake_minimum_required(VERSION 3.27)
project(projectCpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(projectCpp main.cpp
        DateChecker.cpp
        DateChecker.h
        BibliographyRecord.cpp
        BibliographyRecord.h
        Color.cpp
        Color.h
        BibliographyManager.cpp
        BibliographyManager.h
)
