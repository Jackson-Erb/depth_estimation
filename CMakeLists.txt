cmake_minimum_required(VERSION 3.23)
project(depth_estimation)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Fast)

target_sources(Fast
  PRIVATE
    src/fast.cpp
)
target_include_directories(Fast PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(Fast ${OpenCV_LIBS})


