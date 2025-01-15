#include <iostream>
#include <random>
#include <print>

void debug_print(const auto& message, int answer) {
#ifdef DEBUG
    std::println("[DEBUG] {} = {}", message, answer);
#endif
}

bool isCorrect(int, int);

void gameEngine();

int main() {
    gameEngine();
}

void gameEngine() {
    const int lower_bound = 1;
    const int upper_bound = 1000;

    std::default_random_engine random_engine(std::random_device{}());
    std::uniform_int_distribution<int> random_generator {lower_bound, upper_bound};

    char response = 'Y';

    while (response == 'Y' || response == 'y') {
        const int random_answer { random_generator(random_engine) };
        debug_print("Random Integer", random_answer);

        std::cout << "Guess a number (1-1000): ";
        int user_guess;
        std::cin >> user_guess;

        while (!isCorrect(user_guess, random_answer)) {
            std::cout << "Your new guess: ";
            std::cin >> user_guess;
        }

        std::cout << "Do you want to play another game? (Y/N): ";
        std::cin >> response;
    }

    std::cout << "Thanks for the game! Goodbye!";
}


bool isCorrect(const int guess, const int answer) {
    if (guess == answer) {
        std::cout << "You guessed it out!\n";
        return true;
    }

    if (guess < answer) {
        std::cout << "Your guess is lower! Try again.\n";
    }

    if (guess > answer) {
        std::cout << "Your guess is higher! Try again.\n";
    }

    return false;
}
