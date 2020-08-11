# Compiler constants
INCLUDE_DIR = -I /usr/local/include
LINK_DIR =  -L /usr/local/lib
TARGET = -t none
CPU = --cpu 65C02
CONFIG = -C firmware.cfg

# Build folder
BUILD_FOLDER=build

# Source files to be compiled
SOURCES = main.c
# Assembly built code
ASSMBLS = $(SOURCES:%.c=$(BUILD_FOLDER)/%.s)
# Object files to be generated
OBJECTS = $(SOURCES:%.c=$(BUILD_FOLDER)/%.o)

# Build the folder if doesn't exist
$(BUILD_FOLDER):
	mkdir $(BUILD_FOLDER)

# Standard build
all: $(BUILD_FOLDER)
	# Building C source code into asm
	cc65 $(TARGET) $(INCLUDE_DIR) --verbose -O -T -o $(ASSMBLS) $(SOURCES)
	# Building asm code into binary files
	ca65 $(TARGET) $(INCLUDE_DIR) --verbose -o $(OBJECTS) $(ASSMBLS)
	# Linking binary with libraries
	ld65 $(LINK_DIR) $(CONFIG) -v -o $(BUILD_FOLDER)/image $(OBJECTS) c64.lib
	#cl65 $(TARGET) $(INCLUDE_DIR) $(LINK_DIR) $(CONFIG) -o $(BUILD_FOLDER)/image $(SOURCES)

# Display ROM contents
test: $(FIRMWARE_BINARY)
	hexdump -C $(BUILD_FOLDER)/image

clean:
	rm -rf $(BUILD_FOLDER)
