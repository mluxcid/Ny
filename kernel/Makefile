BUILD ?= build

KERNEL := $(BUILD)/kernel.elf

# the default prefix for the RISC-V toolchain
TOOLCHAIN_PREFIX ?= riscv64-unknown-elf-

CC = $(TOOLCHAIN_PREFIX)gcc
LD = $(TOOLCHAIN_PREFIX)ld
AS = $(TOOLCHAIN_PREFIX)as

# C Compiler flags
CFLAGS ?= -O -ggdb
CFLAGS += -nostdlib -nostartfiles
CFLAGS += -fno-stack-protector -fno-common -ffreestanding
CFLAGS += -mcmodel=medany -mno-relax
CFLAGS += -I. -I../include/

# assembler flags
ASFLAGS ?= -g

# linker flags
LDFLAGS = -T linker.ld

SRC := $(shell find -not -path '*/.*' -type f -name '*.c')
AS_SRC := $(shell find -not -path '*/.*' -type f -name '*.S')
OBJ := $(patsubst ./%,$(BUILD)/%,$(SRC:.c=.o) $(AS_SRC:.S=.o))

.PHONY: all

all: kernel

kernel: $(OBJ)
	@echo "[LD]\tlinking $(KERNEL)"
	@$(LD) $(LDFLAGS) -o $(KERNEL) $(OBJ)

# Compilation rules for *.c files.
$(BUILD)/%.o: %.c
	@echo "[CC]\tbuilding $@ from $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Compilation rules for *.S files.
$(BUILD)/%.o: %.S
	@echo "[AS]\tbuilding $@ from $<"
	@mkdir -p $(dir $@)
	@$(AS) $(ASFLAGS) -c $< -o $@

clean:
	@rm $(OBJ) $(KERNEL)
