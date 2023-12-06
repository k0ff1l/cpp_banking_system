cmake_minimum_required(VERSION 3.14)
project(cpp_banking_system)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.0
)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 23)
set(TEST_NAME ${PROJECT_NAME}_tests)

# Добавляем все тесты
file(GLOB TESTS "tests/*_tests.cpp")

# Добавляем все исходные файлы
file(GLOB SOURCE "src/*.cpp")

# Объединяем все списки исходных файлов
set(ALL_SOURCES ${TESTS} ${SOURCE})

add_executable(${TEST_NAME} ${ALL_SOURCES})
target_link_libraries(${TEST_NAME} gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})
