cmake_minimum_required(VERSION 3.14)

project(redactor LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(SKIP_AUTOMOC)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets WebEngineWidgets REQUIRED)

add_executable(redactor
  main.cpp
)
target_link_libraries(redactor Qt5::Core Qt5::WebEngineCore Qt5::WebEngineWidgets Qt5::Widgets)
