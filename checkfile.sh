#!/bin/bash

# Function to check if a file exists in a specific folder
check_file_in_folder() {
    folder_path=$1
    file_name=$2

    if [ -e "$folder_path/$file_name" ]; then
        echo "File '$file_name' exists in folder '$folder_path'."
    else
        echo "File '$file_name' does not exist in folder '$folder_path'."
    fi
}

# Function to check if a file exists on the entire drive
check_file_on_drive() {
    drive_path=$1
    file_name=$2

    if find "$drive_path" -name "$file_name" -print -quit 2>/dev/null; then
        echo "File '$file_name' exists on the drive '$drive_path'."
    else
        echo "File '$file_name' does not exist on the drive '$drive_path'."
    fi
}

# Read the file name from user input
echo "Enter the file name: "
read file_name

# Read the folder path from user input
echo "Enter the folder path (or leave blank to skip): "
read folder_path

# Read the drive path from user input
echo "Enter the drive path (or leave blank to skip): "
read drive_path

# Check if the file exists in the specified folder
if [ -n "$folder_path" ]; then
    check_file_in_folder "$folder_path" "$file_name"
fi

# Check if the file exists on the specified drive
if [ -n "$drive_path" ]; then
    check_file_on_drive "$drive_path" "$file_name"
fi
