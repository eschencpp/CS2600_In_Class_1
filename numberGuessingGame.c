#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int option;
int maximumValue = 10;
int randomNumber;
int optionsMenu();

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
    int inputGuess;
    int inputInteger;
    printf("Enter your guess from 1 - %d: ", maximumValue);
    scanf("%d",&inputGuess);

    if(inputGuess == 'q'){
        printf("The game will return to the menu. \n" );
        optionsMenu();
    }
    // Setting conditions for if the guess is <, >, or equal to randomNumber
    if(inputGuess < randomNumber){
        if(inputGuess < 1){
            printf("Number is out of range. Try again. \n");
            numberGame();
        } else{
        printf("Your guess is lower than the number. Please try again. \n");
        numberGame();
        }
    }
    if(inputGuess > randomNumber){
        if(inputGuess > maximumValue){
        printf("Number is out of range. Try again. \n");
        numberGame();
    } else{
        printf("Your guess is higher than the number. Please try again. \n");
        numberGame();
        }
    }
    if(inputGuess == randomNumber){
    printf("Congratulations you won! The game will now return back to the menu. \n");
    optionsMenu();
    }

    if(inputGuess > maximumValue){
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
    optionsMenu();
}

//Option 3: Thank user for playing and end game.
void exitGame(){
    printf("Thank you for playing the game! The game will now exit. \n");
}

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
int optionsMenu(){
    printf("Choose an option: 1, 2, or 3: ");
    scanf("%d",&option);
    while((option < 1) | (option > 3)){
        printf("Error input out of range. Please try again: \n");
        optionsMenu();
    }
    chooseOption();
    return option;
}

int main(){
    optionsMenu();
    return 0;
}