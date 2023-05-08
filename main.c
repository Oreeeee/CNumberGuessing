#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandRange(int min, int max) {
    return (rand() % (max - min)) + min;
}

int main() {
    const int MAX_GUESSES = 5;

    int minNumber;
    int maxNumber;
    int randomNumber;
    int usedGuessed;
    int lastGuess;

    srand(time(NULL)); /* Initialize RNG */

    /* Ask user for input */
    printf("Give a minimal number: ");
    scanf("%d", &minNumber);

    printf("Give a max number: ");
    scanf("%d", &maxNumber);

    if (minNumber == maxNumber) {
        printf("You can't give the same number for both!\n");
        return 0;
    }

    randomNumber = getRandRange(minNumber, maxNumber);

    while (usedGuessed < MAX_GUESSES) {
        printf("Guess the number! You used %i guesses out of %i: ", usedGuessed, MAX_GUESSES);
        scanf("%d", &lastGuess);

        if (lastGuess == randomNumber) {
            printf("Congratulations! You won!\n");
            return 0;
        }

        if (randomNumber < lastGuess) {
            printf("The number is smaller.\n");
        } else if (randomNumber > lastGuess) {
            printf("The number is bigger.\n");
        }

        usedGuessed++;
    }

    printf("YOU LOST\n");
    printf("The correct number was: %i\n", randomNumber);

    return 0;
}