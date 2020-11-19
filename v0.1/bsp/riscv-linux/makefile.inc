ifeq ($(TARGET_ARCH), cv32e40p)
    BSP_DIR = ./bsp/cv32e40p/

    TARGET_TOOLCHAIN_PREFIX = riscv32-unknown-elf-

    CXXFLAGS += \
        -Os \
        -g \
        -static \
        -mabi=ilp32 \
        -march=rv32imc \
        -Wall \
        -pedantic

    CCFLAGS += CXXFLAGS

    LDFLAGS += \
        -static \
        --specs=nano.specs -u _printf_float \

    TFMICRO_MAKE_FLAGS := "TARGET=mcu_riscv TARGET_ARCH=cv32e40p"

endif