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
        -pedantic \
        -DCV32E40P

    CCFLAGS += CXXFLAGS

    ifneq (,$(findstring spike,$(TAGS)))
    LDFLAGS += \
        --specs=nano.specs -u _printf_float \

    TFMICRO_MAKE_FLAGS := "TARGET=mcu_riscv TARGET_ARCH=cv32e40p TAGS="spike""
	else
    LDFLAGS += \
        -static \
        -nostartfiles \
        --specs=nano.specs -u _printf_float \
        ${BSP_DIR}crtbegin.o \
        -L ${BSP_DIR} \
        -lcv-verif \
        -T ${BSP_DIR}link.ld

    TFMICRO_MAKE_FLAGS := "TARGET=mcu_riscv TARGET_ARCH=cv32e40p"
	endif

endif