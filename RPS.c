#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

// Function to print text with a typing effect
void printWithDelay(const char* text) {
    while (*text) {
        putchar(*text);
        fflush(stdout);

        // Use the appropriate sleep function based on the platform
        #ifdef _WIN32
            Sleep(50);  // Adjust the delay time (in milliseconds) as needed
        #else
            struct timespec delay = {0, 50000};  // 50,000 nanoseconds = 50 microseconds
            nanosleep(&delay, NULL);
        #endif

        text++;
    }
}


// Function to get the user's choice
char getUserChoice() {
    char choice;
    printf("Your turn - [R for Rock, P for Paper, S for Scissors]: ");
    scanf(" %c", &choice);
    return choice;
}

// Function to get the computer's choice
const char* getComputerChoice() {
    const char* choices[] = {"Rock", "Paper", "Scissors"};
    int randomIndex = rand() % 3;
    return choices[randomIndex];
}

// Function to determine the winner
void determineWinner(char userChoice, const char* computerChoice, int* userWins, int* computerWins) {
    printWithDelay("\nCalculating results");
    
    // Use the appropriate sleep function based on the platform
    #ifdef _WIN32
        Sleep(500);  // Add a longer delay after printing "Calculating result" (in milliseconds)
    #else
        struct timespec delay = {0, 500000};  // 500,000 nanoseconds = 500 milliseconds
        nanosleep(&delay, NULL);
    #endif
    
    printWithDelay(".");
    printWithDelay(".");
    printWithDelay(".");
    printWithDelay(".");
    printWithDelay("\n");
    
     if ((userChoice == 'r' || userChoice == 'R')) {
        printf("\nYour choice: Rock\n");
    } else if ((userChoice == 'p' || userChoice == 'P')) {
        printf("\nYour choice: Paper\n");
    } else if ((userChoice == 's' || userChoice == 'S')) {
        printf("\nYour choice: Scissors\n");
    } else {
        printf("\nUh uh uh.. Choose a valid option -> [ R / P / S ]\n\n");
        return;
    }

    printf("My choice: %s\n", computerChoice);

    if ((userChoice == 'R' || userChoice == 'r') && strcmp(computerChoice, "Scissors") == 0 ||
        (userChoice == 'P' || userChoice == 'p') && strcmp(computerChoice, "Rock") == 0 ||
        (userChoice == 'S' || userChoice == 's') && strcmp(computerChoice, "Paper") == 0) {
        printf("\nYOU WIN!\n--------\n");
        (*userWins)++;
    } else if ((userChoice == 'R' || userChoice == 'r') && strcmp(computerChoice, "Paper") == 0 ||
               (userChoice == 'P' || userChoice == 'p') && strcmp(computerChoice, "Scissors") == 0 ||
               (userChoice == 'S' || userChoice == 's') && strcmp(computerChoice, "Rock") == 0) {
        printf("\nI WIN!\n------\n");
        (*computerWins)++;
    } else {
        printf("\nIt's a tie!\n-----------\n");
    }
}

int main() {
    char userChoice;
    const char* computerChoice;
    int userWins = 0;
    int computerWins = 0;

    // Seed the random number generator
    srand(time(NULL));

    printWithDelay("\nx---x---x---x---x---x---x---x---x\n\nWelcome to THE ARENA. I am XAE-13. Let the games begin!\n\n");
    

    printf("\nI> Rock, Paper, Scissors\n------------------------\n");

    for (int i = 0; i < 3; i++) {
        printWithDelay("\nGame ");
        printf("%d>", i + 1);
        printWithDelay("\n");

        printWithDelay("I have made my choice..\n");

        // Get user's choice
        userChoice = getUserChoice();

        // Get computer's choice
        computerChoice = getComputerChoice();

        // Determine the winner
        determineWinner(userChoice, computerChoice, &userWins, &computerWins);
    }
    printf("\nFinal Results:\n");
    printf("You: %d wins\n", userWins);
    printf("Me: %d wins\n", computerWins);

    if (userWins > computerWins) {
        printWithDelay("\nCongratulations! You are the WINNER!\n------------------------------------\n");
    } else if (userWins < computerWins) {
        printWithDelay("\nSorry, you lose!\n----------------\n");
    } else {
        printWithDelay("\nIt's a tie! The competition was fierce.\n-------------------------------\n");
    }

    return 0;
}