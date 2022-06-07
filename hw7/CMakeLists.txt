CMAKE_MINIMUM_REQUIRED(VERSION 3.12)

PROJECT(project)
add_executable(project.bin src/main.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
target_compile_features(project.bin PUBLIC cxx_std_17)

include(FindProtobuf)
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIR})

# Enable Database of compiler flags for YCM
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Uncomment this for debug
# set(CMAKE_BUILD_TYPE Debug)

target_link_libraries(project.bin
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${PROTOBUF_LIBRARY}
)

target_include_directories(project.bin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

