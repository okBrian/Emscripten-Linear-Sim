# Make commands for Emscriptin
#emcmake cmake ..
#make 

cmake_minimum_required(VERSION 3.5.1)
project (a)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE "")
# Output goes to public directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/public")

add_subdirectory(vendor/glad)

file(GLOB_RECURSE APP_SOURCE src/*.h src/*cpp)
add_executable(${PROJECT_NAME} ${APP_SOURCE})

if(EMSCRIPTEN)
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html" LINK_FLAGS "-s WASM=0 -s EXPORTED_RUNTIME_METHODS='[\"main\"]'")
    target_link_options(${PROJECT_NAME} PRIVATE -sUSE_SDL=2)
    target_link_libraries(${PROJECT_NAME} PRIVATE --shell-file ${CMAKE_SOURCE_DIR}/emscripten/shell_minimal.html)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE glad)