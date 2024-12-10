#include <stdbool.h>

#include "../entities/game.h"
#include "./checkSquareUseCase.h"

bool isSquareValid(struct SquarePosition sp) {
  return sp.column >= 0 && sp.column <= 2 && sp.row >= 0 && sp.row <= 2;
} 

bool isSquareOccupied(struct SquarePosition sp, const enum SquareStatus board[3][3]) {
  return board[sp.row][sp.column] != SQUARE_STATUS_EMPTY;
}

bool isSquaresWin(const enum SquareStatus* squares) {
  return squares[0] == squares[1] &&
         squares[0] == squares[2] &&
         squares[1] == squares[2] &&
         squares[0] != SQUARE_STATUS_EMPTY;
}

bool isAllSquaresOccupied(const enum SquareStatus board[3][3]) {
  for (int i = 0; i < 3; i +=1 ) {
    for (int j = 0; j < 3; j += 1) {
      if (board[i][j] == SQUARE_STATUS_EMPTY) {
        return false;
      }
    }
  }

  return true;
}

void updateGameStatus(struct Game* game) {
  enum SquareStatus row1[3] = {game->board[0][0], game->board[0][1], game->board[0][2]};
  enum SquareStatus row2[3] = {game->board[1][0], game->board[1][1], game->board[1][2]};
  enum SquareStatus row3[3] = {game->board[2][0], game->board[2][1], game->board[2][2]};
  enum SquareStatus column1[3] = {game->board[0][0], game->board[1][0], game->board[2][0]};
  enum SquareStatus column2[3] = {game->board[0][1], game->board[1][1], game->board[2][1]};
  enum SquareStatus column3[3] = {game->board[0][2], game->board[1][2], game->board[2][2]};
  enum SquareStatus diagonal1[3] = {game->board[0][0], game->board[1][1], game->board[2][2]};
  enum SquareStatus diagonal2[3] = {game->board[0][2], game->board[1][1], game->board[2][0]};

  bool isWin =
    isSquaresWin(row1) ||
    isSquaresWin(row2) ||
    isSquaresWin(row3) ||
    isSquaresWin(column1) ||
    isSquaresWin(column2) ||
    isSquaresWin(column3) ||
    isSquaresWin(diagonal1) ||
    isSquaresWin(diagonal2);

  if (isWin) {
    game->status = game->playerTurn == PLAYER_TURN_1
      ? GAME_STATUS_PLAYER_1_WIN
      : GAME_STATUS_PLAYER_2_WIN;
    return;
  }

  game->status = isAllSquaresOccupied(game->board)
    ? GAME_STATUS_DRAW
    : GAME_STATUS_RUNNING;
}

void checkSquareUseCase(struct SquarePosition sp, struct Game* game) {
  if (!isSquareValid(sp)) {
    game->userResponse = USER_RESPONSE_INVALID_SQUARE;
    return;
  }

  if (isSquareOccupied(sp, game->board)) {
    game->userResponse = USER_RESPONSE_SQUARE_OCCUPIED;
    return;
  }

  game->board[sp.row][sp.column] = 
    game->playerTurn == PLAYER_TURN_1
      ? SQUARE_STATUS_PLAYER_1
      : SQUARE_STATUS_PLAYER_2;

  updateGameStatus(game);

  game->playerTurn =
    game->playerTurn == PLAYER_TURN_1
      ? PLAYER_TURN_2
      : PLAYER_TURN_1;
 
  game->userResponse = USER_RESPONSE_SUCCESS;
}

