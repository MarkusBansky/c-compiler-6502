# Compiler constants
INCLUDE_DIR = -I /usr/local/include
LINK_DIR =  -L /usr/local/lib
TARGET = -t none
CPU = --cpu 6502
START = -D LOADADDR=$8000
CONFIG = -C none.cfg

# Build folder
BUILD_FOLDER=build

# Source files to be compiled
SOURCES = main.c
# Assembly built code
ASSMBLS = $(SOURCES:%.c=$(BUILD_FOLDER)/%.s)
# Object files to be generated
OBJECTS = $(SOURCES:%.c=$(BUILD_FOLDER)/%.o)

# Build the folder if doesn't exist
.PHONY: $(BUILD_FOLDER)
$(BUILD_FOLDER): clean all test

# Standard build
all: c_asm asm_o o_bin

# Building C source code into asm
# Also remove the file containing the startup code as we
# do not need it for the 6502 Ben Eater's computer
c_asm:
	cc65 $(TARGET) $(CPU) $(INCLUDE_DIR) -v -Oi -T -o $(ASSMBLS) $(SOURCES)
	sed -i.bak '/__STARTUP__/d' $(ASSMBLS)

# Building asm code into binary files
asm_o:
	ca65 $(TARGET) $(CPU) $(INCLUDE_DIR) -v -o $(OBJECTS) $(ASSMBLS)

# Linking binary with libraries
o_bin:
	ld65 $(LINK_DIR) -t none $(START) -v -o $(BUILD_FOLDER)/image.bin $(OBJECTS) c64.lib

# Display ROM contents
test:
	hexdump -C $(BUILD_FOLDER)/image.bin

clean:
	# Remove build folder
	rm -rf $(BUILD_FOLDER)
	# Create build folder
	mkdir $(BUILD_FOLDER)

cl: clean
	cl65 -g -Oi $(TARGET) -C firmware.cfg -o $(BUILD_FOLDER)/image.bin $(SOURCES)
