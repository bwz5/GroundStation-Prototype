cmake_minimum_required(VERSION 3.27)

project(GroundStation C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/mian.cpp
    src/GPS_BOX.cpp
    src/DATA_PROCESSING.cpp
    src/GUI.cpp
)

add_custom_target(open_terminal
    COMMAND open -a Terminal.app
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Opening Terminal"
)

find_package(FLTK REQUIRED CONFIG)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP REQUIRED jsoncpp)

include_directories(${JSONCPP_INCLUDE_DIRS})

add_executable(GroundStation WIN32 MACOSX_BUNDLE src/main.cpp
    src/GPS_BOX.cpp
    src/DATA_PROCESSING.cpp
    src/GUI.cpp)

target_include_directories (GroundStation PUBLIC ${FLTK_INCLUDE_DIRS} ${JSON_INC_PATH})

# specific to mac os TODO: FIND CORRECT JSONCPP ENVIRONMENT
target_link_libraries (GroundStation PUBLIC "-framework cocoa" fltk "/opt/homebrew/Cellar/jsoncpp/1.9.5/lib/libjsoncpp.25.dylib" "/opt/homebrew/Cellar/jsoncpp/1.9.5/lib/libjsoncpp.dylib")


