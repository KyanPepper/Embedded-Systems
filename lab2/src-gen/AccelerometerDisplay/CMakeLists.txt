
cmake_minimum_required(VERSION 3.19)
include(pico_sdk_import.cmake)
project(AccelerometerDisplay LANGUAGES C CXX ASM)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w")
if(CMAKE_BUILD_TYPE STREQUAL "Test")
  set(CMAKE_BUILD_TYPE "Debug")
  if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
    find_program(LCOV_BIN lcov)
    if(LCOV_BIN MATCHES "lcov$")
      set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    else()
      message("Not producing code coverage information since lcov was not found")
    endif()
  else()
    message("Not producing code coverage information since the selected compiler is no gcc")
  endif()
endif()
# Require C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DEFAULT_BUILD_TYPE Debug)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE ${DEFAULT_BUILD_TYPE} CACHE STRING "Choose the type of build." FORCE)
endif()

# Do not print install messages
set(CMAKE_INSTALL_MESSAGE NEVER)
# Colorize compilation output
set(CMAKE_COLOR_DIAGNOSTICS ON)

# Do not clear runtime path of the executable when installing it
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

set(CMAKE_SYSTEM_NAME Rp2040)

# Set default values for build parameters
set(LF_REACTION_GRAPH_BREADTH 3 CACHE STRING "")
set(LF_SINGLE_THREADED 1 CACHE STRING "")
set(LOG_LEVEL 2 CACHE STRING "")
set(NUMBER_OF_WATCHDOGS 0 CACHE STRING "")
pico_sdk_init()

add_subdirectory(core)
target_link_libraries(reactor-c PUBLIC pico_stdlib)
target_link_libraries(reactor-c PUBLIC pico_multicore)
target_link_libraries(reactor-c PUBLIC pico_sync)

set(LF_MAIN_TARGET AccelerometerDisplay)
# Declare a new executable target and list all its sources
add_executable(
    ${LF_MAIN_TARGET}
    lib/schedule.c
    _accelerometerdisplay_main.c
    _accelerometer.c
    _display.c
    AccelerometerDisplay.c
)

pico_add_extra_outputs(${LF_MAIN_TARGET})

find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
  target_link_libraries(${LF_MAIN_TARGET} PUBLIC ${MATH_LIBRARY})
endif()
target_link_libraries(${LF_MAIN_TARGET} PRIVATE reactor-c)
target_include_directories(${LF_MAIN_TARGET} PUBLIC .)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/api)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/core)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/core/platform)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/core/modal_models)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/core/utils)

pico_enable_stdio_usb(${LF_MAIN_TARGET} 1)
pico_enable_stdio_uart(${LF_MAIN_TARGET} 1)
# Set flag to indicate a single-threaded runtime
target_compile_definitions(${LF_MAIN_TARGET} PUBLIC LF_SINGLE_THREADED=1)

    install(
        TARGETS ${LF_MAIN_TARGET}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )

include("robot-lib.txt")

# Define directory in which files from the 'files' target directive will be put.
target_compile_definitions(${LF_MAIN_TARGET} PUBLIC LF_TARGET_FILES_DIRECTORY="${CMAKE_CURRENT_LIST_DIR}")


