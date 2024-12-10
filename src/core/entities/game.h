#ifndef GAME_H
#define GAME_H

enum GameStatus {
  GAME_STATUS_RUNNING,
  GAME_STATUS_PLAYER_1_WIN,
  GAME_STATUS_PLAYER_2_WIN,
  GAME_STATUS_DRAW
};

enum PlayerTurn {
  PLAYER_TURN_1,
  PLAYER_TURN_2
};

enum SquareStatus {
  SQUARE_STATUS_EMPTY,
  SQUARE_STATUS_PLAYER_1,
  SQUARE_STATUS_PLAYER_2,
};

enum UserAction {
  USER_ACTION_SUCCESS,
  USER_ACTION_SQUARE_OCCUPIED,
  USER_ACTION_INVALID_SQUARE
};

struct Game {
  enum GameStatus status;
  enum PlayerTurn playerTurn;
  enum SquareStatus board[3][3];
  enum UserAction userAction;
};

#endif // GAME_H
