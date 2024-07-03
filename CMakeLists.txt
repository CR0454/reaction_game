cmake_minimum_required(VERSION 3.27)
project(reaction_game)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_DEFAULT 11)
file(GLOB_RECURSE SRC "include/*.hpp" "include/*.h" "src/*.cpp")

set(OpenCV_DIR "D:/OpenCV/build/install/")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

message(STATUS "OpenCV library status:")
message(STATUS " config: ${OpenCV_DIR}")
message(STATUS " version: ${OpenCV_VERSION}")
message(STATUS " libraries: ${OpenCV_LIBS}")
message(STATUS " include path: ${OpenCV_INCLUDE_DIRS}")
add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})