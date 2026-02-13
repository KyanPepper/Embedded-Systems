#!/bin/bash

# Robot Upload Menu Script
# Compiles and uploads Lingua Franca programs to the Pololu 3pi+ 2040 robot

PROJECT_DIR="/Users/kyankotschevar-smead/Desktop/Projects/Embedded-Systems"
SRC_DIR="$PROJECT_DIR/src"
BIN_DIR="$PROJECT_DIR/bin"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}   Pololu Robot Upload Menu${NC}"
echo -e "${BLUE}========================================${NC}"
echo ""

# Get list of .lf files
cd "$SRC_DIR"
files=(*.lf)

# Check if any files exist
if [ ${#files[@]} -eq 0 ] || [ ! -e "${files[0]}" ]; then
    echo -e "${RED}No .lf files found in $SRC_DIR${NC}"
    exit 1
fi

# Display menu
echo -e "${YELLOW}Available programs:${NC}"
echo ""
for i in "${!files[@]}"; do
    # Remove .lf extension for display
    name="${files[$i]%.lf}"
    echo -e "  ${GREEN}$((i+1))${NC}) $name"
done
echo ""
echo -e "  ${GREEN}q${NC}) Quit"
echo ""

# Get user selection
read -p "Select a program to upload (1-${#files[@]}): " choice

# Handle quit
if [[ "$choice" == "q" || "$choice" == "Q" ]]; then
    echo "Goodbye!"
    exit 0
fi

# Validate input
if ! [[ "$choice" =~ ^[0-9]+$ ]] || [ "$choice" -lt 1 ] || [ "$choice" -gt ${#files[@]} ]; then
    echo -e "${RED}Invalid selection${NC}"
    exit 1
fi

# Get selected file
selected="${files[$((choice-1))]}"
name="${selected%.lf}"
elf_name=$(echo "$name" | tr '[:upper:]' '[:lower:]')

echo ""
echo -e "${BLUE}Selected: ${GREEN}$name${NC}"
echo ""

# Step 1: Compile
echo -e "${YELLOW}[1/2] Compiling $selected...${NC}"
cd "$SRC_DIR"
if lfc "$selected"; then
    echo -e "${GREEN}✓ Compilation successful${NC}"
else
    echo -e "${RED}✗ Compilation failed${NC}"
    exit 1
fi

echo ""

# Step 2: Upload
echo -e "${YELLOW}[2/2] Uploading to robot...${NC}"
echo -e "${BLUE}Make sure your robot is in BOOTSEL mode (hold BOOTSEL while plugging in USB)${NC}"
echo ""
read -p "Press Enter when ready to upload (or 'q' to quit): " confirm

if [[ "$confirm" == "q" || "$confirm" == "Q" ]]; then
    echo "Upload cancelled. The .elf file is ready in $BIN_DIR"
    exit 0
fi

# Find the elf file (try both lowercase and original case)
ELF_FILE=""
if [ -f "$BIN_DIR/$elf_name.elf" ]; then
    ELF_FILE="$BIN_DIR/$elf_name.elf"
elif [ -f "$BIN_DIR/$name.elf" ]; then
    ELF_FILE="$BIN_DIR/$name.elf"
else
    echo -e "${RED}Could not find .elf file in $BIN_DIR${NC}"
    echo "Looking for: $elf_name.elf or $name.elf"
    ls -la "$BIN_DIR"/*.elf 2>/dev/null
    exit 1
fi

echo "Uploading: $ELF_FILE"
if picotool load -x "$ELF_FILE"; then
    echo ""
    echo -e "${GREEN}✓ Upload successful! Robot is running $name${NC}"
else
    echo -e "${RED}✗ Upload failed${NC}"
    echo "Make sure the robot is in BOOTSEL mode and connected via USB"
    exit 1
fi
