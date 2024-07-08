#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int get_user_choice();
int get_computer_choice();
void determine_winner(int user_choice, int computer_choice, int *user_score, int *computer_score);

int main() {
    int user_score = 0, computer_score = 0;
    int total_rounds, current_round = 0;

    printf("Welcome to Rock-Paper-Scissors!\n");
    printf("How many rounds would you like to play?: ");
    scanf("%d", &total_rounds);

    while (current_round < total_rounds) {
        printf("\nRound %d\n", current_round + 1);

        int user_choice = get_user_choice();
        int computer_choice = get_computer_choice();

        determine_winner(user_choice, computer_choice, &user_score, &computer_score);

        printf("Score: You %d - %d Computer\n", user_score, computer_score);

        current_round++;
    }

    
    printf("\nFinal Score:\n");
    printf("You: %d\n", user_score);
    printf("Computer: %d\n", computer_score);
    
    if (user_score > computer_score) {
        printf("Congratulations! You win!\n");
    } else if (user_score < computer_score) {
        printf("Computer wins. Better luck next time!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}


int get_user_choice() {
    int choice;
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 3) {
        printf("Invalid choice. Please enter a number between 1 and 3: ");
        scanf("%d", &choice);
    }
    return choice;
}


int get_computer_choice() {
    srand(time(NULL));
    return rand() % 3 + 1;  
}


void determine_winner(int user_choice, int computer_choice, int *user_score, int *computer_score) {
    printf("\nYour choice: ");
    switch (user_choice) {
        case 1:
            printf("Rock\n");
            break;
        case 2:
            printf("Paper\n");
            break;
        case 3:
            printf("Scissors\n");
            break;
    }

    printf("Computer's choice: ");
    switch (computer_choice) {
        case 1:
            printf("Rock\n");
            break;
        case 2:
            printf("Paper\n");
            break;
        case 3:
            printf("Scissors\n");
            break;
    }

    
    if (user_choice == computer_choice) {
        printf("It's a draw!\n");
    } else if ((user_choice == 1 && computer_choice == 3) ||
               (user_choice == 2 && computer_choice == 1) ||
               (user_choice == 3 && computer_choice == 2)) {
        printf("You win this round!\n");
        (*user_score)++;
    } else {
        printf("Computer wins this round!\n");
        (*computer_score)++;
    }
}
