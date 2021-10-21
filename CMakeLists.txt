cmake_minimum_required(VERSION 3.20)
project(MessengerDB)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Sql
        REQUIRED)
#record sources, headers, resources
set(SOURCE)
set(HEADER)
set(RES_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}../Resources")

# add cross-platforms source files and header files
list(APPEND SOURCE
        Classes/ConnectDb.cpp)

list(APPEND HEADER
        Classes/ConnectDb.h)

# mark app compile info and libs info
set(all_code_files
        ${HEADER}
        ${SOURCE}
        main.cpp)

add_executable(${PROJECT_NAME} ${all_code_files})
target_link_libraries(MessengerDB
        Qt5::Core
        Qt5::Sql
        )

