cmake_minimum_required(VERSION 2.4)
project(freeserf)

include(CheckIncludeFiles)
include(CheckFunctionExists)


include_directories(${PROJECT_BINARY_DIR})
add_definitions(-DHAVE_CONFIG_H)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

include(VcsVersion)
find_package(SDL2_mixer REQUIRED)

if(SDLMIXER_FOUND)
    include_directories(${SDLMIXER_INCLUDE_DIR})
    set(ENABLE_SDL2_MIXER 1)
    set(AUDIO_C "sdlmixer")
else()
    set(AUDIO_C "dummy")
endif()

check_include_files(byteswap.h CMAKE_HAVE_BYTESWAP_H)
check_include_files(endian.h CMAKE_HAVE_ENDIAN_H)
check_include_files(fcntl.h CMAKE_HAVE_FCNTL_H)
check_include_files(inttypes.h CMAKE_HAVE_INTTYPES_H)
check_include_files(memory.h CMAKE_HAVE_MEMORY_H)
check_include_files(stdint.h CMAKE_HAVE_STDINT_H)
check_include_files(stdlib.h CMAKE_HAVE_STDLIB_H)
check_include_files(strings.h CMAKE_HAVE_STRINGS_H)
check_include_files(string.h CMAKE_HAVE_STRING_H)
check_include_files(sys/endian.h CMAKE_HAVE_SYS_ENDIAN_H)
check_include_files(sys/mman.h CMAKE_HAVE_SYS_MMAN_H)
check_include_files(sys/param.h CMAKE_HAVE_SYS_PARAM_H)
check_include_files(sys/stat.h CMAKE_HAVE_SYS_STAT_H)
check_include_files(sys/types.h CMAKE_HAVE_SYS_TYPES_H)
check_include_files(unistd.h CMAKE_HAVE_UNISTD_H)

check_function_exists(atexit CMAKE_HAVE_ATEXIT)
check_function_exists(getpagesize CMAKE_HAVE_GETPAGESIZE)
check_function_exists(memset CMAKE_HAVE_MEMSET)
check_function_exists(mmap CMAKE_HAVE_MMAP)
check_function_exists(munmap CMAKE_HAVE_MUNMAP)
check_function_exists(strtol CMAKE_HAVE_STRTOL)

configure_file(config.h.cmake config.h @ONLY)

set(PACKAGE_BUGREPORT "https://github.com/freeserf/freeserf/issues")
configure_file(definitions.h.cmake definitions.h)

set(SOURCES src/version.cpp
            src/audio-${AUDIO_C}.cpp
            src/serf.cpp
            src/mission.cpp
            src/game-init.cpp
            src/pqueue.cpp
            src/game.cpp
            src/sdl-video.cpp
            src/freeserf.cpp
            src/random.cpp
            src/panel.cpp
            src/savegame.cpp
            src/minimap.cpp
            src/notification.cpp
            src/viewport.cpp
            src/building.cpp
            src/popup.cpp
            src/gfx.cpp
            src/player.cpp
            src/map.cpp
            src/pathfinder.cpp
            src/log.cpp
            src/data-source-dos.cpp
            src/list.cpp
            src/interface.cpp
            src/flag.cpp
            src/gui.cpp
)

set(HEADERS src/map.hpp
            src/gfx.hpp
            src/debug.hpp
            src/freeserf_endian.hpp
            src/version.hpp
            src/player.hpp
            src/mission.hpp
            src/pqueue.hpp
            src/interface.hpp
            src/notification.hpp
            src/flag.hpp
            src/savegame.hpp
            src/log.hpp
            src/random.hpp
            src/minimap.hpp
            src/panel.hpp
            src/data.hpp
            src/freeserf.hpp
            src/viewport.hpp
            src/game.hpp
            src/sdl-video.hpp
            src/gui.hpp
            src/list.hpp
            src/audio.hpp
            src/misc.hpp
            src/building.hpp
            src/game-init.hpp
            src/serf.hpp
            src/popup.hpp
            src/pathfinder.hpp
)

add_executable(freeserf ${SOURCES} ${HEADERS})
target_link_libraries(freeserf -lSDL2 -lSDL2_mixer -lm)
