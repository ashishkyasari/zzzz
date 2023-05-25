#include <iostream>
#include <string>
#include <map>
#include <sstream>

// Function to display the frequency list of commands
void displayCommandFrequencies(const std::map<std::string, int>& commandCounts) {
    std::cout << "Command frequencies:\n";
    for (const auto& pair : commandCounts) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
}

// Function to display the top 5 commands
void displayTopCommands(const std::map<std::string, int>& commandCounts) {
    std::cout << "Top 5 commands:\n";
    int count = 0;
    for (const auto& pair : commandCounts) {
        std::cout << pair.first << ": " << pair.second << "\n";
        if (++count == 5) break;
    }
}

int main() {
    std::map<std::string, int> commandCounts;

    // Read commands from the user during runtime
    std::string command;
    while (std::getline(std::cin, command)) {
        if (!command.empty()) {
            ++commandCounts[command];
        }
    }

    // Display the frequency list of commands
    displayCommandFrequencies(commandCounts);

    // Display the top 5 commands
    displayTopCommands(commandCounts);

    return 0;
}
