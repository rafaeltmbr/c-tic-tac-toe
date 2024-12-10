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

enum UserResponse {
  USER_RESPONSE_SUCCESS,
  USER_RESPONSE_SQUARE_OCCUPIED,
  USER_RESPONSE_INVALID_SQUARE
};

struct Game {
  enum GameStatus status;
  enum PlayerTurn playerTurn;
  enum SquareStatus board[3][3];
  enum UserResponse userResponse;
};

#endif // GAME_H
