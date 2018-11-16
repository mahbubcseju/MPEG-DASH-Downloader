
cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_MODULE_PATH})

project(MpegDownloader)

find_package(LibAV REQUIRED)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})



include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../libdash/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../build/bin/)

file(GLOB mpeg_SOURCE 
${CMAKE_CURRENT_SOURCE_DIR}/libdashframework/MPD/*.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Decoder/*.cpp
${CMAKE_CURRENT_SOURCE_DIR}/libdashframework/Adaptation/*.cpp
${CMAKE_CURRENT_SOURCE_DIR}/libdashframework/Buffer/*.cpp
${CMAKE_CURRENT_SOURCE_DIR}/libdashframework/Input/*.cpp
${CMAKE_CURRENT_SOURCE_DIR}/libdashframework/Portable/*.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Managers/*.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Downloader/*.cpp
${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)


include_directories(
${CMAKE_CURRENT_SOURCE_DIR}/Decoder
${CMAKE_CURRENT_SOURCE_DIR}/libdashframework/MPD
${CMAKE_CURRENT_SOURCE_DIR}/libdashframework/Adaptation
${CMAKE_CURRENT_SOURCE_DIR}/libdashframework/Buffer
${CMAKE_CURRENT_SOURCE_DIR}/libdashframework/Input
${CMAKE_CURRENT_SOURCE_DIR}/libdashframework/Portable
${CMAKE_CURRENT_SOURCE_DIR}/Managers
${CMAKE_CURRENT_SOURCE_DIR}/Downloader

)



add_executable(mpegdownloader ${mpeg_SOURCE})

target_link_libraries(mpegdownloader  ${OpenCV_LIBS} ${LIBAV_LIBRARIES} dash -lpthread )
