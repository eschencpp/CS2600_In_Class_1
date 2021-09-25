#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int option;
int maximumValue = 10;
int randomNumber;
void optionsMenu();
void fileWrite();

//Random number generator
int randomNumberG(){
    srand(time(NULL));
    randomNumber = (rand() % maximumValue) + 1;
    return randomNumber;
}

/* Option 1: Ask for user input for number 1-10
If input == random number then user wins and returns to menu
If input != random number then tell if too high or low and prompt for guess
If q input then game should end and return to menu  */
void numberGame(){
    char inputGuess[20];
    int inputInteger;
    // Ask for user input
    printf("Enter your guess from 1 - %d: ", maximumValue);
    scanf("%s",&inputGuess);
    inputInteger = atoi(inputGuess);
    // Input validation for characters
    if(!(isdigit(inputGuess[0]))){
        if(inputGuess[0] == 'q'){
            printf("The game will return to the menu. \n" );
            optionsMenu();
            return;
        } else{
            printf("Not a valid entry. Please enter q to exit or a number to continue guessing. \n");
            numberGame();
        }
    }
    // Setting conditions for if the guess is <, >, or equal to randomNumber
    if(inputInteger < randomNumber){
        if(inputInteger < 1){
            printf("Number is out of range. Try again. \n");
            numberGame();
        } else{
        printf("Your guess is lower than the number. Please try again. \n");
        numberGame();
        }
    }
    if(inputInteger > randomNumber){
        if(inputInteger > maximumValue){
        printf("Number is out of range. Try again. \n");
        numberGame();
    } else{
        printf("Your guess is higher than the number. Please try again. \n");
        numberGame();
        }
    }
    if(inputInteger == randomNumber){
    printf("Congratulations you won! The game will now return back to the menu. \n");
    optionsMenu();
    }

    // Input validation for maximum value
    if(inputInteger > maximumValue){
        printf("Number is out of range. Try again. \n");
        numberGame();
    }

}
//Option 2: Prompt input for max value and write to file. Set max value and ensure they do not exceed it.
void changeMaxNumber(){
    printf("Enter maximum value: ");
    scanf("%d",&maximumValue);
    if((maximumValue > 2147483647) || (maximumValue < 0)){
        printf("Maximum value out of range. Please try again \n");
        changeMaxNumber();
    }
    fileWrite();
    optionsMenu();
}

//Option 3: Thank user for playing and end game.
void exitGame(){
    printf("Thank you for playing the game! The game will now exit. \n");
    exit;
}


// Helper method for options menu
void chooseOption(){
    switch(option){
        case 1 :
            randomNumberG();
            numberGame();
            break;
        case 2 :
            changeMaxNumber();
            break;
        case 3 :
            exitGame();
            break;
    }
}

//Ask for user input 1 , 2 , or 3
void optionsMenu(){
    printf("Choose an option: 1, 2, or 3: ");
    scanf("%d",&option);
    if((option < 1) | (option > 3)){
        optionsMenu();
        return;
    }
    chooseOption();
    return;
}

void fileWrite(){
    FILE *f = fopen("file.txt", "w");
    if (f == NULL){
    printf("Error opening file!\n");
    exit(1);
    }
    fprintf(f, "%d", maximumValue);
    fclose(f);
}

void readMaxValue(){
    FILE *f = fopen("file.txt", "r");
    if (f == NULL){
    printf("Error opening file!\n");
    exit(1);
    }
    fscanf(f, "%d", &maximumValue);
    fclose(f);
}

int main(){
    readMaxValue();
    optionsMenu();
    return 0;
}