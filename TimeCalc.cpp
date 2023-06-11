// Written by Harvey Gough
// P2708961
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Start of Variable definition. Explanation of variable usage when they are used.

/* Going to use recursion, coding each option as a function in order to deal with multiple issues:
    1. DivisionByZero Error
    2. Incrrect inputs
   It provides a slower time complexity (than iteration), however this program is not that resource-heavy 
   and only deals with basic computation.
*/

// Declaring all void functions up here so that they can be accessed by menuFunction
// (had errors if this is not here)
void optionOne();
void optionTwo();
void optionThree();
void optionFour();
void optionFive();
void optionSix();

int iMenuChoice;
int iSecondsTime;
int iMinsTime;
int iHoursTime;

int iConfirmationOfExit;


double dTimeInHours;
double dTimeInMinutes;
double dTimeInSeconds;


string sConfirmExit;
string sExitChoice;

string asChoices[6] = {"1. Convert Seconds to hours", "2. Convert seconds to minutes", "3. Convert minutes to hours", "4. Convert hours to seconds", "5. Convert minutes to seconds", "6. Exit the program"}; 



void menuFunction() {
    cout << "Simple Time Calculator!" << endl;

    // asChoices[] used to print options to the screen.
    for (int i = 0; i < 6; i++) {
        cout << asChoices[i] << endl;
    }

    cout << "Enter a choice (1-6)" << endl;
    cin >> iMenuChoice; // Used for choosing user option. Used as comparison in switch/case statement for different options.

    switch(iMenuChoice) {
        case 1:
            optionOne();
        case 2:
            optionTwo();
        case 3:
            optionThree();
        case 4:
            optionFour();
        case 5:
            optionFive();
        case 6: 
            optionSix();
        default:
            // catching invalid inputs.
            cout << "Please enter a valid option!" << endl << endl << endl << endl;

            menuFunction();
    }

}

void optionOne() {
    cout << endl << endl << "Option 1 selected! (seconds to hours)" << endl << endl;
    cout << "Please make sure that time is entered in seconds." << endl;
    cout << "Please enter seconds to be converted into hours: ";
    cin >> iSecondsTime; // input time in seconds

    if (iSecondsTime == 0) {
        cout << "Input is zero. this will provide an error. Please enter a number greater than zero";
        optionOne();
    }          

    dTimeInHours = iSecondsTime / 3600;
    // 60 seconds in a minute, 60 minutes in an hour
    // 60 * 60 = 3600, so 3600 is the number to be divided by
    // using double to round to 2dp.

    cout << iSecondsTime << " seconds in hours is " << dTimeInHours << " hour/s." << endl << endl;
    cout << endl << endl;
    cout << "Returning to menu..." << endl << endl << endl;
    menuFunction();
}


void optionTwo() {
    cout << endl << endl << "Option 2 selected! (seconds to minutes)" << endl << endl;
    cout << "Please make sure that time is entered in seconds." << endl;
    cout << "Please enter seconds to be converted into minutes: ";
    cin >> iSecondsTime;

    if (iSecondsTime == 0) {
        cout << "Input is zero. this will provide an error. Please enter a number greater than zero";
        optionTwo();
    }
    dTimeInMinutes = iSecondsTime / 60;
    // 60 seconds in a minute
    // so 60 is the number to be divided by
    // using double to round to 2dp.

    cout << iSecondsTime << " seconds in minutes is " << dTimeInMinutes << " minute/s." << endl << endl;
    cout << endl << endl;
    cout << "Returning to menu..." << endl << endl << endl;
    menuFunction();
}


void optionThree() {
    cout << endl << endl << "Option 3 selected! (minutes to hours)" << endl << endl;
    cout << "Please make sure that time is entered in minutes." << endl;
    cout << "Please enter seconds to be converted into hours: ";
    cin >> iMinsTime;

    // catching zero input

    if (iMinsTime == 0) {
        cout << "Input is zero. this will provide an error. Please enter a number greater than zero";
        optionThree();
    }
    dTimeInHours = iMinsTime / 60;
    // 60 minutes in an hour
    // so 60 is the number to be divided by
    // using double to round to 2dp.

    cout << iMinsTime << " minutes in hours is " << dTimeInHours << " hour/s." << endl << endl;
    cout << endl << endl;
    cout << "Returning to menu..." << endl << endl << endl;
    menuFunction();
}


void optionFour() {
    cout << endl << endl << "Option 4 selected! (hours to seconds)" << endl << endl;
    cout << "Please make sure that time is entered in hours." << endl;
    cout << "Please enter seconds to be converted into seconds: ";
    cin >> iHoursTime;
    
    // catching zero input
    if (iHoursTime == 0) {
        cout << "Input is zero. this will provide an error. Please enter a number greater than zero";
        optionFour();
    }

    dTimeInSeconds = iHoursTime * 3600;
    // Using divisoin co-efficient as multiplier

    cout << iHoursTime << " hours in seconds is " << dTimeInSeconds << " second/s." << endl << endl;
    cout << endl << endl;
    cout << "Returning to menu..." << endl << endl << endl;
    menuFunction();
}

void optionFive() {
    cout << endl << endl << "Option 5 selected! (minutes to seconds)" << endl << endl;
    cout << "Please make sure that time is entered in minutes." << endl;
    cout << "Please enter seconds to be converted into seconds: ";
    cin >> iMinsTime;
    cout << endl << endl;
    
    // catching zero input
    if (iMinsTime == 0) {
        cout << "Input is zero. this will provide an error. Please enter a number greater than zero";
        optionFour();
    }

    dTimeInSeconds = iMinsTime * 60;
    // Using divisoin co-efficient as multiplier

    cout << iMinsTime << " minutes in seconds is " << dTimeInSeconds << " second/s." << endl << endl;
    cout << endl << endl;
    cout << "Returning to menu..." << endl << endl << endl;
    menuFunction();
}

void optionSix() {
    cout << "Option 6 selected! (exit the program)" << endl << endl;
    cout << "Are you sure that you would like to exit the program? (1/0) " << endl;
    cin >> iConfirmationOfExit;

    // getting user confirmation
    if (iConfirmationOfExit == 1) {
        cout << endl << "Program closing. Goodbye!" << endl << endl;
        exit(0);
    } else if (iConfirmationOfExit == 0) {
        cout << endl << "Program will not close. Re-directing to menu..." << endl << endl;
        menuFunction();
    }
    else {
        cout << endl << "Invalid input. Please press 1 for yes and 0 for no." << endl << endl;
        optionSix();
    }
}

// Driver program
int main() {
    menuFunction();
}