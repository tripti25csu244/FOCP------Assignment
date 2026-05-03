#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::replace
#include <random>    // For better random number generation
#include <ctime>     // To seed our random number generator

int main() {
    // 1. Setup the Random Number Generator
    // We seed it with the current time so the result is different every time you run it.
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // 2. Get the user's name
    std::string name;
    std::cout << "Enter your name (if you dare): ";
    std::getline(std::cin, name);

    // 3. Store the roast templates in a vector
    // We use {name} as a placeholder that we will find and replace later.
    std::vector<std::string> roasts = {
        "I'd explain it to you, {name}, but I left my English-to-Dingbat dictionary at home.",
        "{name}, you're the reason the gene pool needs a lifeguard.",
        "I’ve seen puddles deeper than your personality, {name}.",
        "If laughter is the best medicine, {name}, your face must be curing the world.",
        "I'm not saying you're slow, {name}, but it takes you two hours to watch 60 Minutes.",
        "{name}, you have a face for radio and a voice for silent movies.",
        "I’d slap you, {name}, but that would be animal abuse.",
        "You're like a cloud, {name}. When you disappear, it’s a beautiful day.",
        "I love what you've done with your hair, {name}. How do you get it to come out of your nostrils like that?",
        "Don't be ashamed of who you are, {name}. That's your parents' job."
    };

    // 4. Pick a random index from the vector
    int randomIndex = std::rand() % roasts.size();
    std::string selectedRoast = roasts[randomIndex];

    // 5. Replace the {name} placeholder with the actual name
    // We look for the position of "{name}" and swap it out.
    std::string placeholder = "{name}";
    size_t pos = selectedRoast.find(placeholder);

    if (pos != std::string::npos) {
        selectedRoast.replace(pos, placeholder.length(), name);
    }

    // 6. Show the final result
    std::cout << "\n--- THE VERDICT ---" << std::endl;
    std::cout << selectedRoast << std::endl;
    std::cout << "-------------------\n" << std::endl;

    return 0;
}
