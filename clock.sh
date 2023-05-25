#!/bin/bash

# Function to clear the screen
clear_screen() {
    clear
}

# Function to display the digital clock
display_clock() {
    while true; do
        # Clear the screen
        clear_screen

        # Get the current time
        current_time=$(date +"%T")

        # Display the current time
        echo "Digital Clock"
        echo "--------------"
        echo "Current Time: $current_time"

        # Sleep for 1 second
        sleep 1

        # Move the cursor up to overwrite the previous displ
    done
}

# Run the digital clock
display_clock
