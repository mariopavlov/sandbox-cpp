// GuessingGame.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <random>

// Verify input from the user is the correct range
bool verifyInput(int, int, int);

// Compare Guess and Answer numbers
// return true if correct guess is made
bool isCorrect(int, int);