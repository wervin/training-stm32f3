set(CMAKE_SYSTEM_NAME  Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)

set(OBJCOPY "${ARM_TOOLCHAIN_SYSROOT}/bin/llvm-objcopy")
set(SIZE "${ARM_TOOLCHAIN_SYSROOT}/bin/llvm-size")
set(CMAKE_C_COMPILER "${ARM_TOOLCHAIN_SYSROOT}/bin/clang")
set(CMAKE_ASM_COMPILER "${ARM_TOOLCHAIN_SYSROOT}/bin/clang")
set(CMAKE_LINKER "${ARM_TOOLCHAIN_SYSROOT}/bin/lld")

# Compiler flags for Cortex‑M4
set(TARGET_FLAGS
    "--target=armv7m-none-eabi"
    "-mcpu=cortex-m4"
    "-mfpu=fpv4-sp-d16"
    "-mfloat-abi=softfp"
    "-Wall"
    "-Wextra"
    "-Wpedantic"
)

# Linker flags
set(LINKER_FLAGS
    "-Tstm32f303xc.ld"
    "-Wl,-Map=app.map"
    "-nostartfiles"
)

# Definitions
set(DEFINITIONS
    STM32F303xC
)

# Sources
set(SOURCES
    isr.c
    main.c
    os.c
    port.c
    startup.c
    ll/rcc.c
    ll/usart.c
)

# Includes
set(INCLUDES
    cmsis
    device
)

# Copy linker script to build directory
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/stm32f303xc.ld ${CMAKE_BINARY_DIR}/project/stm32f303xc.ld COPYONLY)

# Define the executable
add_executable(app.elf ${SOURCES})

add_dependencies(app.elf arm-toolchain)

# Ensure our flags apply
target_compile_options(app.elf PRIVATE ${TARGET_FLAGS})
target_include_directories(app.elf PRIVATE ${INCLUDES})
target_compile_definitions(app.elf PRIVATE ${DEFINITIONS})
target_link_options(app.elf PRIVATE ${TARGET_FLAGS} ${LINKER_FLAGS})

# Generate .bin and .hex after building the ELF
add_custom_command(TARGET app.elf POST_BUILD
    COMMAND ${OBJCOPY} -O binary app.elf app.bin
    COMMAND ${OBJCOPY} -O ihex app.elf app.hex
    COMMAND ${SIZE} --format=sysv -x app.elf
    COMMENT "Generating binary and hex files"
)