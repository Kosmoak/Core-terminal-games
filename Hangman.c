#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRIES 7

// Function to read words from the dictionary file
int readWordsFromFile(char words[][MAX_WORD_LENGTH], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }

    int count = 0;
    while (fgets(words[count], MAX_WORD_LENGTH, file) != NULL) {
        // Remove newline character
        words[count][strcspn(words[count], "\n")] = '\0';
        count++;
    }

    fclose(file);
    return count;
}

// Function to randomly select a word from the list
void chooseRandomWord(char chosenWord[MAX_WORD_LENGTH], char words[][MAX_WORD_LENGTH], int wordCount) {
    srand(time(NULL));
    int randomIndex = rand() % wordCount;
    strcpy(chosenWord, words[randomIndex]);
}

// Function to display the current state of the word
void displayWord(const char *word, const char *guessedLetters) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (strchr(guessedLetters, word[i]) != NULL) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

// Function to print Hangman based on the number of incorrect guesses
void printHangman(int incorrectGuesses) {
    switch (incorrectGuesses) {
        case 0:
            printf("  +---+\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |_\n");
            printf("       \n");
            break;
        case 1:
            printf("  +---+\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf(" /    |_\n");
            printf("       \n");
            break;
        case 2:
            printf("  +---+\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf(" / \\  |_\n");
            printf("       \n");
            break;
        case 3:
            printf("  +---+\n");
            printf("      |\n");
            printf("      |\n");
            printf("  |   |\n");
            printf(" / \\  |_\n");
            printf("       \n");
            break;
        case 4:
            printf("  +---+\n");
            printf("      |\n");
            printf("      |\n");
            printf(" /|   |\n");
            printf(" / \\  |_\n");
            printf("       \n");
            break;
        case 5:
            printf("  +---+\n");
            printf("      |\n");
            printf("      |\n");
            printf(" /|\\  |\n");
            printf(" / \\  |_\n");
            printf("       \n");
            break;
	case 6:
            printf("  +---+\n");
            printf("      |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" / \\  |_\n");
            printf("       \n");
            break;
        case 7:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" / \\  |\n");
            printf("      |\n\n");
            break;
        default:
            break;
    }
}

// Function to check if the player has guessed the entire word
int hasGuessedWord(const char *word, const char *guessedLetters) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (strchr(guessedLetters, word[i]) == NULL) {
            return 0; // Not all letters are guessed
        }
    }
    return 1; // All letters are guessed
}

int main() {
    char words[1000][MAX_WORD_LENGTH];
    int wordCount = readWordsFromFile(words, "dictionary.txt");

    if (wordCount == 0) {
        return 1; // Exit if there was an error reading the dictionary file
    }

    char chosenWord[MAX_WORD_LENGTH];
    char guessedLetters[MAX_WORD_LENGTH];
    int triesLeft = MAX_TRIES;
    int incorrectGuesses = 0;

    chooseRandomWord(chosenWord, words, wordCount);
    memset(guessedLetters, 0, sizeof(guessedLetters)); // Initialize guessedLetters to all zeros

    printf("Welcome to Hangman!\n");

    while (triesLeft > 0) {
        printf("\nTries left: %d\n", triesLeft);
        displayWord(chosenWord, guessedLetters);
        printHangman(incorrectGuesses);

        char guess;
        printf("Enter your guess: ");
        scanf(" %c", &guess);

        // Check if the guessed letter is in the word
        if (strchr(chosenWord, guess) != NULL) {
            printf("Correct guess!\n");
        } else {
            printf("Incorrect guess!\n");
            triesLeft--;
            incorrectGuesses++;
        }

        guessedLetters[strlen(guessedLetters)] = guess; // Add the guessed letter to the list

        // Check if the player has guessed the entire word
        if (hasGuessedWord(chosenWord, guessedLetters)) {
            printf("\nCongratulations! You guessed the word :-) -> %s\n", chosenWord);
            break;
        }
    }

    if (triesLeft == 0) {
        printf("\nSorry, you ran out of tries. The word was: %s\n", chosenWord);
        printHangman(incorrectGuesses); // Print the full Hangman when the player loses
    }

    return 0;
}
