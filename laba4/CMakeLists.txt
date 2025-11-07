cmake_minimum_required(VERSION 3.10)
project(oop_lab04)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Основное приложение
file(GLOB SOURCES "src/*.cpp" "main.cpp")
add_executable(oop_lab04 ${SOURCES})

# Установка Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB TEST_SOURCES "tests/*.cpp" "src/*.cpp")
add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests gtest_main)

# Добавление тестов в тестовый набор
add_test(NAME MyProjectTests COMMAND tests)
