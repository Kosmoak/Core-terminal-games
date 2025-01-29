#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORD_COUNT 50
#define WORD_LENGTH 20

char* words[WORD_COUNT] ={
    "Algorithm",
    "Binary",
    "Compiler",
    "Database",
    "Encryption",
    "Firmware",
    "Gateway",
    "Hardware",
    "Internet",
    "Java",
    "Kernel",
    "Linux",
    "Malware",
    "Network",
    "Object",
    "Protocol",
    "Query",
    "Runtime",
    "Script",
    "Terminal",
    "Unix",
    "Virtual",
    "Web",
    "Zip",
    "Array",
    "Byte",
    "Cache",
    "Debug",
    "Ethernet",
    "Function",
    "Gigabyte",
    "Hash",
    "Interface",
    "JSON",
    "Keyword",
    "Loop",
    "Module",
    "Node",
    "Python",
    "Queue",
    
    "Stack",
    "Thread",
    "URL",
    "VPN",
    "Widget"
};


void shuffleWord(char* word) {
    int length = strlen(word);
    for (int i = 0; i < length - 1; i++) {
        int j = i + rand() % (length - i);
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
}

void playGame() {
    int index = rand() % WORD_COUNT;
    char scrambledWord[WORD_LENGTH];
    strcpy(scrambledWord, words[index]);
    shuffleWord(scrambledWord);

    printf("\nUnscramble the word: %s\n", scrambledWord);

    char guess[WORD_LENGTH];
    printf("\nEnter your guess: ");
    fgets(guess, sizeof(guess), stdin);
    guess[strlen(guess) - 1] = '\0'; // Remove newline character from input

    if (strcmp(guess, words[index]) == 0) {
        printf("\nCongratulations! You unscrambled the word!\n");
    } else {
        printf("\nSorry, the correct word was: %s\n\n", words[index]);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
	printf("\n---x---x---x---x---x---x---x---x---x\n");
    printf("\nWelcome to Scramble!\n");

    while (1) {
        playGame();

        char choice;
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &choice);

        if (choice != 'Y' && choice != 'y') {
            printf("\nExiting the game. Goodbye!\n\n");
            break;
        }

        getchar(); // Clear the newline character from input buffer
    }

    return 0;
}