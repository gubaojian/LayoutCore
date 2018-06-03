cmake_minimum_required(VERSION 3.11)
project(RenderUI)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")

set(SOURCE_FILES
        main.cpp
        common/Encoding.cpp
        graphics/geometry.cpp
        graphics/Paint.cpp
        graphics/Font.cpp
        graphics/Canvas.cpp
        ui/Div.cpp
        ui/Image.cpp
        ui/Text.cpp
        ui/TextLine.cpp)


add_executable(RenderUI ${SOURCE_FILES})
target_link_libraries(RenderUI cairo)

add_executable(HelloCario HelloCairo.cpp)
target_link_libraries(HelloCario cairo)


target_include_directories(RenderUI PUBLIC
        graphics/ ui/ common/)