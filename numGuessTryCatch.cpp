// Copyright (c) 2022 Peter Sobowale All rights reserved.
//
// This program asks the user for a random number from
// 0 to 9 and checks if it is the same as the correct
// number that is generated
#include <iostream>
#include <random>

int main() {
    // declare variables
    int userNumber, randomNumber;
    std::string userNumberAsAString;

    // get user input for a number form 0 to 9
    std::cout << "Enter a number from 0 to 9: ";
    std::cin >> userNumberAsAString;

    // initialize random seed
    std::random_device rseed;
    std::mt19937 rgen(rseed());

    // generate random number
    std::uniform_int_distribution<int> idist(0, 9);
    randomNumber = idist(rgen);

    // try catch
    try {
        userNumber = std::stoi(userNumberAsAString);
        // checks if user input is equal to random number
        if (userNumber == randomNumber) {
            std::cout << "You guessed correctly!" << std::endl;
        } else {
            std::cout << "\nYou guessed wrong :(\nThe right answer was "
            << randomNumber << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "\n" << userNumberAsAString + " is not an integer."
        << std::endl;
    }
    std::cout << "Thanks for playing";
}
