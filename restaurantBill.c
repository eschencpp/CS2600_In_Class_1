#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int randomMeal;
char mealName[10];
float costOfMeal;
float taxPercent;
float taxTotal;
float tipPercent;
float tipTotal;
float totalBill;

//Randomly picks 1 meal and displays meal and cost using rand()
int pickMeal(){
    srand((unsigned)time(NULL));
    randomMeal= rand() % 4;
    switch(randomMeal){
        case 0 :
            strcpy(mealName, "Salad");
            costOfMeal = 9.95;
            break;
        case 1 :
            strcpy(mealName, "Soup");
            costOfMeal = 4.55;
            break;
        case 2 :
            strcpy(mealName, "Sandwhich");
            costOfMeal = 13.25;
            break;
        case 3 :
            strcpy(mealName, "Pizza");
            costOfMeal = 22.35;
            break;
    }
    
    printf("Your meal is %s and the cost is %.2f \n" , mealName, costOfMeal);
}
//Accept user input for tax %, calculates, and displays tax amount
int tax(){
    printf( "Enter the tax percentage from 0-100%: ");
    scanf("%f",&taxPercent);
    // Input validation to ensure tax percent is not negative.
    while(taxPercent < 0){
        printf("Invalid percentage. Please try again. \n");
        printf( "Enter the tax percentage from 0-100%: ");
        scanf("%f",&taxPercent);
    }
    printf("The tax percent is %.2f% \n",taxPercent);
    taxTotal = costOfMeal * taxPercent * .01;
    printf("The tax total is: $%.2f \n", taxTotal);
}
//Accept user input for tip %, calculates, and displays tip amount
int tip(){
    printf("Enter the tip percentage: ");
    scanf("%f",&tipPercent);
    // Input validation to ensure tip percent is not negative.
     while(tipPercent < 0){
        printf("Invalid percentage. Please try again. \n");
        printf( "Enter the tip percentage from 0-100%: ");
        scanf("%f",&tipPercent);
    }
    printf("The tip percent is %.2f% \n",tipPercent);
    tipTotal = costOfMeal * tipPercent * .01;
    printf("The tip total is: $%.2f \n", tipTotal);
}
//Adds meal cost, tax, and tip and displays total bill
int finalBill(){
    totalBill = costOfMeal + taxTotal + tipTotal;
    printf("The total bill is $%.2f", totalBill);
}

int main(){
    pickMeal();
    tax();
    tip();
    finalBill();
}