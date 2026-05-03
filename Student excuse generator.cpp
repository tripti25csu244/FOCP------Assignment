#include <iostream>
#include <string>
#include <vector>
#include <random> // For random number generation
#include <ctime>   // For seeding the random engine

int main() {
    // 1. Ask for the user's name
    std::cout << "Welcome to the Student Excuse Generator!" << std::endl;
    std::cout << "Enter your name: ";
    std::string userName;
    std::getline(std::cin, userName);

    // 2. Store 10 excuse templates in a vector
    // We use "{name}" as a placeholder to find and replace later
    std::vector<std::string> templates = {
        "{name}'s alarm clock joined a cult and refused to beep.",
        "A rogue squirrel stole {name}'s laptop charger.",
        "{name} accidentally boarded a plane to Hawaii instead of the bus.",
        "The ink in {name}'s pen turned back into a squid and swam away.",
        "{name} was busy negotiating a peace treaty between the cat and the dog.",
        "A localized gravitational anomaly kept {name} pinned to the bed.",
        "{name}'s homework was confiscated by a high-ranking government official.",
        "The ghost of Pythagoras appeared and challenged {name} to a duel.",
        "{name} spent the morning helping a time traveler find 1985.",
        "{name} tried to update their brain's software, but it required a reboot."
    };

    // 3. Randomly choose one excuse
    // We seed the random engine with the current time
    std::mt19937 generator(static_cast<unsigned int>(std::time(0)));
    std::uniform_int_distribution<int> distribution(0, templates.size() - 1);
    int randomIndex = distribution(generator);
    
    std::string chosenExcuse = templates[randomIndex];

    // 4. Replace the {name} placeholder with the actual name
    std::string target = "{name}";
    size_t pos = chosenExcuse.find(target);
    
    if (pos != std::string::npos) {
        // replace(starting_position, length_to_replace, new_string)
        chosenExcuse.replace(pos, target.length(), userName);
    }

    // 5. Display the final excuse
    std::cout << "\n--- YOUR OFFICIAL EXCUSE ---" << std::endl;
    std::cout << chosenExcuse << std::endl;

    return 0;
}
