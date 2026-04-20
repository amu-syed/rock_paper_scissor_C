#include <stdio.h>

typedef enum {
ROCK,
PAPER,
SCISSORS
} Choice;

Choice get_player_choice(int player_number);
const char* choice_to_string(Choice choice);
int determine_winner(Choice player1, Choice player2);

Choice get_player_choice(int player_number) {
char input;

while (1) {
printf("Player %d, enter your choice (r)ock, (p)aper, or (s)cissors: ", player_number);
scanf(" %c", &input);

if (input == 'r' || input == 'R') {
return ROCK;
} else if (input == 'p' || input == 'P') {
return PAPER;
} else if (input == 's' || input == 'S') {
return SCISSORS;
} else {
printf("Invalid choice. Please enter r, p, or s.\n");
}
}
}

const char* choice_to_string(Choice choice) {
if (choice == ROCK) {
return "Rock";
} else if (choice == PAPER) {
return "Paper";
} else {
return "Scissors";
}
}

int determine_winner(Choice player1, Choice player2) {
if (player1 == player2) {
return 0;
}

if ((player1 == ROCK && player2 == SCISSORS) ||
(player1 == PAPER && player2 == ROCK) ||
(player1 == SCISSORS && player2 == PAPER)) {
return 1;
}

return 2;
}

int main(void) {
Choice player1_move;
Choice player2_move;
char play_again_choice;
int winner;

do {
printf("\n--- Rock Paper Scissors ---\n");

player1_move = get_player_choice(1);
player2_move = get_player_choice(2);

printf("\nPlayer 1 chose: %s\n", choice_to_string(player1_move));
printf("Player 2 chose: %s\n", choice_to_string(player2_move));

winner = determine_winner(player1_move, player2_move);

if (winner == 0) {
printf("It's a tie!\n");
} else if (winner == 1) {
printf("Player 1 wins!\n");
} else {
printf("Player 2 wins!\n");
}

if (player1_move != player2_move) {
if ((player1_move == ROCK && player2_move == SCISSORS) ||
(player2_move == ROCK && player1_move == SCISSORS)) {
printf("Rock smashes Scissors.\n");
} else if ((player1_move == PAPER && player2_move == ROCK) ||
(player2_move == PAPER && player1_move == ROCK)) {
printf("Paper covers Rock.\n");
} else {
printf("Scissors cuts Paper.\n");
}
}

printf("\nDo you want to play again? (y/n): ");
scanf(" %c", &play_again_choice);

} while (play_again_choice == 'y' || play_again_choice == 'Y');

printf("Thanks for playing!\n");
return 0;
}
