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

set(SOURCES src/version.c
            src/audio-${AUDIO_C}.c
            src/serf.c
            src/mission.c
            src/game-init.c
            src/pqueue.c
            src/game.c
            src/sdl-video.c
            src/freeserf.c
            src/random.c
            src/panel.c
            src/savegame.c
            src/minimap.c
            src/notification.c
            src/viewport.c
            src/building.c
            src/popup.c
            src/gfx.c
            src/player.c
            src/map.c
            src/pathfinder.c
            src/log.c
            src/data-source-dos.c
            src/list.c
            src/interface.c
            src/flag.c
            src/gui.c
)

set(HEADERS src/map.h
            src/gfx.h
            src/debug.h
            src/freeserf_endian.h
            src/version.h
            src/player.h
            src/mission.h
            src/pqueue.h
            src/interface.h
            src/notification.h
            src/flag.h
            src/savegame.h
            src/log.h
            src/random.h
            src/minimap.h
            src/panel.h
            src/data.h
            src/freeserf.h
            src/viewport.h
            src/game.h
            src/sdl-video.h
            src/gui.h
            src/list.h
            src/version-vcs.h
            src/audio.h
            src/misc.h
            src/building.h
            src/game-init.h
            src/serf.h
            src/popup.h
            src/pathfinder.h
)

set(CMAKE_C_FLAGS "-std=gnu99")
add_executable(freeserf ${SOURCES} ${HEADERS})
target_link_libraries(freeserf -lSDL2 -lSDL2_mixer -lm)
