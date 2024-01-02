#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
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

TARGET = c1m2

RM := rm -rf

BIN_DIR = ../bin

DEBUG_OBJS = $(patsubst %.c, $(BIN_DIR)/%.o, $(SOURCES))

# Architecture Specific Flags
CPU = cortex-m4
INSTRUCTIONS_MODE = thumb
ARCH = armv7e-m
SPECS = nosys.specs
FLOAT_ABI = hard
FPU = fpv4-sp-d16
LINKER_FILE = ../msp432p401r.lds


# Compiler Flags and Defines
CFLAGS = -g -std=c99 $(INCLUDES) -Wall -O0 -MD #-Werror
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

	SOURCES += startup_msp432p401r_gcc.c \
		system_msp432p401r.c \
		interrupts_msp432p401r_gcc.c

	INCLUDES += -I../include/msp432 \
		-I../include/CMSIS

endif


#----------------------------------------------------
# Phony targets
#----------------------------------------------------
.PHONY: build compile-all dirs clean files


compile-all: $(DEBUG_OBJS) | dirs

build: $(BIN_DIR)/$(TARGET).out

$(BIN_DIR)/$(TARGET).out: $(DEBUG_OBJS) | dirs
	@echo "Compilin main target!"
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)
	$(SIZE) -Atd $@

# Preprocessor targets (.i) 
$(BIN_DIR)/%.i: %.c | dirs
	$(CC) -E $< -o $@ $(CFLAGS)

# Preprocessor targets (.asm) 
$(BIN_DIR)/%.asm: %.c | dirs
	$(CC) -S $< -o $@ $(CFLAGS)

# Preprocessor targets (.o) 
$(BIN_DIR)/%.o: %.c | dirs
	$(CC) -c $< -o $@ $(CFLAGS)

#----------------------------------------------------
# Include dependencies
#----------------------------------------------------
-include $(BIN_DIR)/*.d


files:
	@echo "C files"
	@echo $(SOURCES)
	@echo $(DEBUG_OBJS)
	@echo "$(CFLAGS) $(LDFLAGS)"

dirs:
	@mkdir -p  $(BIN_DIR)

clean:
	@$(RM) $(BIN_DIR)/*
	@echo "Clean!"