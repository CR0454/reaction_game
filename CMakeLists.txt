cmake_minimum_required(VERSION 3.26)
project(reaction_game)

set(OpenCV_DIR "C:/Users/oezge/OpenCV/build/install")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE SRC "include/*.hpp" "include/*.h" "src/*.cpp")

add_executable(reaction_game ${SRC})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

