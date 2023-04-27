cmake_minimum_required(VERSION 3.26.3)
project(brutty LANGUAGES CXX)

find_package(fmt REQUIRED)
find_package(libzip REQUIRED)

file(GLOB SOURCE
  CONFIGURE_DEPENDS
  "src/*.cpp"
)
add_executable(${PROJECT_NAME} ${SOURCE})

message(CMAKE_EXPORT_COMPILE_COMMANDS= "${CMAKE_EXPORT_COMPILE_COMMANDS}")

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt libzip::zip)
