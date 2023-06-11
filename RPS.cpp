// Written by Harvey Gough
// P2708961
#include <iostream>
#include <cstring>

using namespace std;


// function declaration
void menuFunction();
void gameFunction();
void calculationOfWinner();
void gameRepetitionHandler();
void gameCompletion();

// Variable declaration
int iPlayerChoice; 
string asOptionsForAI[3] = {"rock", "paper", "scissors"};
string sTemp;


int iPlayerChoiceIndex;
int iRandomChoiceIndex;
int iOutcomeValue;
int iRepetitionGameChoice;

// score tally variables
int iPlayerWins;
int iBotWins;



// Using numbers to represent outcomes. 0 is a loss, 1 is a draw and 2 is a win.
// Draws will only occur if both player and bot pick the same option.
// Based on what option the player and the bot choose, the option will be given the index
// Indexes will return values in the field (2, 1, 0).
int aiWinLoss[3][3] = {
    {1, 0, 2},                  // Rock v. Rock, Rock v. Paper, Rock v. Scissors
    {2, 1, 0},                  // Paper v. Rock, Paper v. Paper, Paper v. Scissors
    {0, 2, 1}                   // Scissors v. Rock, Scissors v. Paper, Scissors v. Scissors
};

string asOptions[3] = {"rock", "paper", "scissors"};

// Auth variables.
string sPassword;
string sCorrectPass = "QWERTY";
// 4uTh0rISaTI0n_P3rm1Tt3D

// using functions to separate the program
void menuFunction() {
    cout << "Rock Paper Scissors Game!" << endl << endl;
    cout << "Checking for authorisation..." << endl;
    cout << "Please enter the password: ";
    cin >> sPassword;
    if (sPassword == sCorrectPass) {
        cout << "Access Granted! Game starting.";
        gameFunction();
    }
    else {
        cout << "Access denied. Try again." << endl << endl;
        menuFunction();
    }
}

void gameFunction() {
    cout << endl << endl << "Please enter either 1, 2 or 3 for rock, paper or scissors: ";
    cin >> iPlayerChoice;
    // switch/case to determine index value
    switch (iPlayerChoice)
    {
    case 1:
        iPlayerChoiceIndex = 0;
        break;
    case 2:
        iPlayerChoiceIndex = 1;
        break;
    case 3:
        iPlayerChoiceIndex = 2;
        break;
    default:
        cout << "Please enter either 1, 2 or 3.";
        gameFunction();
    }
    
    calculationOfWinner();

}

void calculationOfWinner() {
    // seeding the random number generator with the time, to ensure that a different se =t of random numbers are generated on each execution.
    srand((unsigned) time (0)); 
    // Generates a random number between 0 and 2 for the index to my 2d array
    iRandomChoiceIndex = rand() % 2;
    
    cout << endl << asOptionsForAI[iPlayerChoiceIndex] << " selected!" << endl << endl << endl;
    
    // gets the outcome value from the 2d array
    iOutcomeValue = aiWinLoss[iPlayerChoiceIndex][iRandomChoiceIndex];


    // determining end text based on value returned from index.
    if (iOutcomeValue == 2) {
        cout << "Player wins!" << endl << endl << "The AI selected " << asOptionsForAI[iRandomChoiceIndex] << ".";
        iPlayerWins += 1;
        cout << endl << endl << endl << "The score is - Player: " << iPlayerWins << ", Bot: " << iBotWins << endl << endl;
        gameRepetitionHandler();

    } else if (iOutcomeValue == 1) {
        cout << "There was a draw." << endl << endl << "Both Player and AI selected " << asOptionsForAI[iRandomChoiceIndex] << ".";
        cout << endl << endl << endl << "The score is - Player: " << iPlayerWins << ", Bot: " << iBotWins << endl << endl;
        gameRepetitionHandler();

    } else if (iOutcomeValue == 0) {
        cout << "Player lost." << endl << endl << "The AI selected " << asOptionsForAI[iRandomChoiceIndex] << ".";
        iBotWins += 1;                
        cout << endl << endl << endl << "The score is - Player: " << iPlayerWins << ", Bot: " << iBotWins << endl << endl;
        gameRepetitionHandler();

    } else { // error catching incase of any errors such as index out of range for boundary/erroneous cases that slip through
        cout << "there was an error in computation. Referring back to the selection screen. Press any key and then enter to continue. ";
        // making a "press any key to continue".
        cin >> sTemp;
        gameFunction();
    }
    gameCompletion();
}

// display final score and exit program
void gameCompletion() {
    // display final scores
    cout << endl << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << endl << endl << "Games complete! The final score is: " << endl;
    cout << "Player: " << iPlayerWins << ", Bot: " << iBotWins << endl;
    cout << "Goodbye!";
    exit(0);
}

void gameRepetitionHandler() {
    // asks for repetition. if yes recursive call, if no end program.
    cout << "Would you like to play another round? 1/0" << endl;
    cin >> iRepetitionGameChoice;
    if (iRepetitionGameChoice == 1) {
        cout << "Game will reset. Score will be saved." << endl << endl << endl;
        gameFunction();
    }

    else if (iRepetitionGameChoice == 0) {
        cout << "Game will finish. Final tally will be displayed." << endl << endl;
    }

    else {
        cout << "Please enter a number: 1/0.";
        gameRepetitionHandler();
    }
}


int main() {
    menuFunction();
}