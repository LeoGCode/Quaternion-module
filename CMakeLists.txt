cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME Quaternion)

set(Sources
    ${PROJECT_NAME}.cpp
    Test${PROJECT_NAME}.cpp
)

project("${PROJECT_NAME}")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

add_executable(Quaternion ${Sources})
target_link_libraries(Quaternion ${GTEST_LIBRARIES} pthread)
target_link_libraries(${PROJECT_NAME} gcov)