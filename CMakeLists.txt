cmake_minimum_required(VERSION 3.23)

project(go-module)
set(PROJECT_MODULE_NAME go-module)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_target_properties(PROPERTIES PREFIX "")

# rapidjson config
set(RAPIDJSON_HAS_STDSTRING ON)
set(Protobuf_USE_STATIC_LIBS ON)

file(GLOB_RECURSE PROJECT_SOURCE_FILES "src/*.h" "src/*.hpp" "src/*.cpp"
        "src/events/*.h" "src/events/*.hpp" "src/events/*.cpp")
file(GLOB_RECURSE PROJECT_PROTO_FILES "src/*.proto")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

# protobuf dependency
find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# cpp-sdk dependency
include("vendors/cpp-sdk/CMakeLists.txt")
include_directories("vendors/cpp-sdk")

# rapidjson dependency
include_directories("vendors/rapidjson/include")

# go-module headers
include_directories(
        "src"
)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROJECT_PROTO_FILES})

add_library(
        ${PROJECT_MODULE_NAME} SHARED
        ${PROJECT_SOURCE_FILES} ${PROTO_SRCS} ${PROTO_HDRS}
)

add_dependencies(${PROJECT_NAME} alt-sdk)
# target_include_directories(${PROJECT_NAME} PRIVATE ${PROTO_HDRS})
target_link_libraries(${PROJECT_NAME}  ${Protobuf_LIBRARIES})
