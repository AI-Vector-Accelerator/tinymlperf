ifeq ($(TARGET_ARCH), cv32e40p-ml)
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

	# Check if Spike execution is required

	ifneq (,$(findstring spike,$(TAGS)))
		LDFLAGS += \
			--specs=nano.specs -u _printf_float \

		TFMICRO_MAKE_FLAGS := "TARGET=mcu_riscv TARGET_ARCH=cv32e40p TAGS="cv32e40p-ml spike""
	else
		LDFLAGS += \
			-static \
			-nostartfiles \
			--specs=nano.specs -u _printf_float \
			${BSP_DIR}crtbegin.o \
			-L ${BSP_DIR} \
			-lcv-verif \
			-T ${BSP_DIR}link.ld

		TFMICRO_MAKE_FLAGS := "TARGET=mcu_riscv TARGET_ARCH=cv32e40p TAGS="cv32e40p-ml""
	endif

endif


