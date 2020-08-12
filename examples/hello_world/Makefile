# Compiler constants
INCLUDE_DIR = -I /usr/local/include
LINK_DIR =  -L /usr/local/lib
TARGET = -t none
START = -D LOADADDR=$8000 # -S 8000
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
all:
	# Create build directory
	mkdir $(BUILD_FOLDER)
	# Building C source code into asm
	cc65 $(TARGET) $(INCLUDE_DIR) -v -O -T -o $(ASSMBLS) $(SOURCES)
	# Building asm code into binary files
	ca65 $(TARGET) $(INCLUDE_DIR) -v -o $(OBJECTS) $(ASSMBLS)
	# Linking binary with libraries
	ld65 $(LINK_DIR) $(CONFIG) $(START) -v -o $(BUILD_FOLDER)/image.bin $(OBJECTS) c64.lib

# Display ROM contents
test:
	hexdump -C $(BUILD_FOLDER)/image.bin

clean:
	rm -rf $(BUILD_FOLDER)
