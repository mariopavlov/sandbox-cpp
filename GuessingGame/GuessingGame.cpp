// GuessingGame.cpp : Defines the entry point for the application.
//

#include "GuessingGame.h"

using namespace std;

int main()
{
	int lowLimit = 1;
	int highLimit = 500;

	// Configure random generation
	default_random_engine engine(random_device{}());
	uniform_int_distribution<int> randomInt(lowLimit, highLimit);

	char continuePlaing = 'y';

	while (continuePlaing == 'y')
	{
		// Generate Random number for the game
		const int answer{ randomInt(engine) };

		// Collect user input
		cout << "Guess a number between 1 and 500: ";
		int guess;
		cin >> guess;

		while (verifyInput(lowLimit, highLimit, guess) == false)
		{
			cout << "Please provide a number between " << lowLimit << " and " << highLimit << ": ";
			cin >> guess;
		}

		while (isCorrect(guess, answer) == false)
		{
			// Collect guesses from user untill correct one is given
			cin >> guess;
		}

		cout << "You have guessed the number!\n"
			<< "Do you want to play another game? (y/n): ";
		cin >> continuePlaing;

		cout << endl;
	}

	cout << "Thank you for playing! Goodbye!" << endl;

	return 0;
}

bool verifyInput(int lowLimit, int highLimit, int number)
{
	if (number < lowLimit)
	{
		return false;
	}
	if (number > highLimit)
	{
		return false;
	}

	return true;
}

bool isCorrect(int guess, int answer) 
{
	// Correct Answer
	if (guess == answer)
	{
		return true;
	}

	// Incorrect guess, give more details
	if (guess > answer)
	{
		cout << "Number is higher. Try again: ";
	}
	else
	{
		cout << "Number is lower. Try again: ";
	}

	return false;
}
