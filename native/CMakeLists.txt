cmake_minimum_required(VERSION 3.16)
project(ti83_raylib C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew" "/usr/local")
find_package(raylib 5.0 QUIET)
if(NOT raylib_FOUND)
  find_library(RAYLIB_LIB raylib REQUIRED)
  find_path(RAYLIB_INC raylib.h REQUIRED)
  add_library(raylib UNKNOWN IMPORTED)
  set_target_properties(raylib PROPERTIES
    IMPORTED_LOCATION "${RAYLIB_LIB}"
    INTERFACE_INCLUDE_DIRECTORIES "${RAYLIB_INC}")
endif()

# Mechanical ASM->C runtime (no raylib) + generated pages.
set(TI_RUNTIME
  src/ti_lcd.c
  src/ti_keypad.c
  src/ti_font.c
  src/ti_mmu.c
  src/ti_hw.c
  src/ti_cpu.c
  src/ti_mem.c
  src/ti_runtime.c
  gen/page00.c
  gen/page01.c
  gen/page02.c
  gen/page03.c
  gen/page04.c
  gen/page05.c
  gen/page06.c
  gen/page07.c
  gen/page24.c
  gen/page25.c
  gen/page26.c
  gen/page27.c
  gen/page28.c
  gen/page29.c
  gen/page31.c
  gen/dispatch.c
  gen/stubs.c
)

add_executable(ti83_raylib
  src/main.c
  src/host_raylib.c
  ${TI_RUNTIME}
)

target_include_directories(ti83_raylib PRIVATE src gen)
target_link_libraries(ti83_raylib PRIVATE raylib)

if(APPLE)
  target_link_libraries(ti83_raylib PRIVATE
    "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
endif()

add_executable(ti83_boot_smoke
  src/boot_smoke.c
  ${TI_RUNTIME}
)
target_include_directories(ti83_boot_smoke PRIVATE src gen)

install(TARGETS ti83_raylib ti83_boot_smoke RUNTIME DESTINATION bin)
