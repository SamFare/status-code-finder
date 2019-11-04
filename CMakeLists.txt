cmake_minimum_required (VERSION 3.15.4)
include(FetchContent)

message(${CMAKE_VERSION})

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.8.0
)

FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG        v3.7.0
)

if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

FetchContent_MakeAvailable(googletest)
FetchContent_MakeAvailable(nlohmann_json)
include(GoogleTest)

project (sc)
add_executable(sc src/main.cpp)
set_property(TARGET sc PROPERTY CXX_STANDARD 17)
target_link_libraries(sc PRIVATE nlohmann_json::nlohmann_json)


project(test)
add_executable(test tests.cpp)
target_link_libraries(test gtest gtest_main nlohmann_json::nlohmann_json)
gtest_discover_tests(test TEST_PREFIX discovered_test:)
set_property(TARGET test PROPERTY CXX_STANDARD 17)
