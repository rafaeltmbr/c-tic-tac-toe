#include <stdio.h>
#include <stdlib.h>

#include "./gameView.h"
#include "../../core/entities/square.h"

char squareStatusSymbol(enum SquareStatus status) {
  switch (status) {
    case SQUARE_STATUS_EMPTY:        return ' ';
    case SQUARE_STATUS_PLAYER_1:     return 'x';
    case SQUARE_STATUS_PLAYER_2:     return 'o';
  }

  return '?';
}

const char* userResponseMessage(enum UserResponse userResponse) {
  switch (userResponse) {
    case USER_RESPONSE_SUCCESS:
      return "";

    case USER_RESPONSE_INVALID_SQUARE:
      return "Invalid square."; 

    case USER_RESPONSE_SQUARE_OCCUPIED:
      return "Square already occupied.";
  }

  return "";
}

void printGameStatus(const struct Game* game) {
  switch (game->status) {
    case GAME_STATUS_RUNNING:
      printf(
        "\nPlayer %s turn. %s\n",
        game->playerTurn == PLAYER_TURN_1 ? "1" : "2",
        userResponseMessage(game->userResponse)
      );
      break;
   case GAME_STATUS_PLAYER_1_WIN:
     printf("\nPlayer 1 Victory!\n");
     break;
   case GAME_STATUS_PLAYER_2_WIN:
     printf("\nPlayer 2 Victory!\n");
     break;
   case GAME_STATUS_DRAW:
     printf("\nGame Drawn\n");
     break;
  }
}

void showGame(const struct Game* game) {
  system("clear");
  printf("\n    TIC TAC TOE  \n\n");
  printf("     a   b   c   \n");
  printf("   ------------- \n");

  printf(
    "1  | %c | %c | %c | \n",
    squareStatusSymbol(game->board[0][0]),
    squareStatusSymbol(game->board[0][1]),
    squareStatusSymbol(game->board[0][2])
  );
  printf("   ------------- \n");

  printf(
    "2  | %c | %c | %c | \n",
    squareStatusSymbol(game->board[1][0]),
    squareStatusSymbol(game->board[1][1]),
    squareStatusSymbol(game->board[1][2])
  );
  printf("   ------------- \n");

  printf(
    "3  | %c | %c | %c | \n",
    squareStatusSymbol(game->board[2][0]),
    squareStatusSymbol(game->board[2][1]),
    squareStatusSymbol(game->board[2][2])
  );
  printf("   ------------- \n");

  printGameStatus(game);
}

int parseColumn(char column) {
  switch (column) {
    case 'a':
    case 'A':
      return 0;

    case 'b':
    case 'B':
      return 1;

    case 'c':
    case 'C':
      return 2;
  }

  return -1;
}

int parseRow(char row) {
  switch (row) {
    case '1': return 0;
    case '2': return 1;
    case '3': return 2;
  }

  return -1;
}

struct SquarePosition readUserInput() {
  char input[3];

  printf("Square: ");
  scanf("%2s", input);
  
  struct SquarePosition square = {
    .column = parseColumn((char) input[0]),
    .row = parseRow(input[1])
  };

  return square;
} 
        
