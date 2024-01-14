#******************************************************************************
# Copyright (C) 2024 by Roberto Castro
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Roberto Castro are not liable for any misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Compilation system for the introduction to embedded systems course
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#		- build: Compile all build units and the final executable
#		- compile-all: Compile all build units without linking
#
# Platform Overrides:
#		- Use PLATFORM=HOST to generate development platform-specific binaries
#		- Use PLATFORM=MSP432 to generate embedded platform binaries
#
#------------------------------------------------------------------------------

include sources.mk

TARGET = c1final

RM := rm -rf

SRC_DIR = src
BIN_DIR = bin

DEBUG_OBJS = $(patsubst %.c, $(BIN_DIR)/%.o, $(SOURCE))

# Architecture Specific Flags
CPU = cortex-m4
INSTRUCTIONS_MODE = thumb
ARCH = armv7e-m
SPECS = nosys.specs
FLOAT_ABI = hard
FPU = fpv4-sp-d16
LINKER_FILE = msp432p401r.lds

# Compiler Flags and Defines
CFLAGS = -g -std=c99 $(INCLUDES) -Wall -O0 -MD -DCOURSE1 -lm#-Werror
LDFLAGS =


ifeq ($(PLATFORM),HOST)
	CC = gcc
	SIZE = size
	CFLAGS += -DHOST
else
	CC = arm-none-eabi-gcc
	SIZE = arm-none-eabi-size

	CFLAGS += -DMSP432 \
		-m$(INSTRUCTIONS_MODE) \
		-mcpu=$(CPU) \
		-march=$(ARCH) \
		-mfloat-abi=$(FLOAT_ABI) \
		-mfpu=$(FPU) \
		--specs=$(SPECS)

	LDFLAGS += -Wl,-Map=$(BIN_DIR)/$(TARGET).map \
		-T $(LINKER_FILE)

	SOURCE += startup_msp432p401r_gcc.c \
		system_msp432p401r.c \
		interrupts_msp432p401r_gcc.c

	INCLUDES += -I./include/msp432 \
		-I./include/CMSIS

endif

ifeq ($(DEBUG),1)
	CFLAGS += -DVERBOSE
endif

#----------------------------------------------------
# Phony targets
#----------------------------------------------------
.PHONY: build compile-all clean dirs files

compile-all: $(DEBUG_OBJS) | dirs

build: $(BIN_DIR)/$(TARGET).out

$(BIN_DIR)/$(TARGET).out: $(DEBUG_OBJS) | dirs
	@echo "Compilin main target!"
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)
	$(SIZE) -Atd $@

# Preprocessor targets (.i) 
$(BIN_DIR)/%.i: $(SRC_DIR)/%.c | dirs
	$(CC) -E $< -o $@ $(CFLAGS)

# Assembler targets (.asm) 
$(BIN_DIR)/%.asm: $(SRC_DIR)/%.c | dirs
	$(CC) -S $< -o $@ $(CFLAGS)

# Preprocessor targets (.o) 
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | dirs
	$(CC) -c $< -o $@ $(CFLAGS)

#----------------------------------------------------
# Include dependencies
#----------------------------------------------------
-include $(BIN_DIR)/*.d

dirs:
	@mkdir -p  $(BIN_DIR)


files:
	@echo "C files"
	@echo $(SOURCES)
	@echo $(DEBUG_OBJS)
	@echo "$(CFLAGS) $(LDFLAGS)"

clean:
	@$(RM) $(BIN_DIR)/*
	@echo "Clean!"