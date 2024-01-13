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

# Add any additional dependencies or include directories if needed
# target_include_directories(projectCpp PRIVATE path/to/your/includes)
# target_link_libraries(projectCpp PRIVATE your_additional_libraries)
