#include "./startGameUseCase.h"

struct Game startGameUseCase() {
  struct Game game = {
    .status = GAME_STATUS_RUNNING,
    .playerTurn = PLAYER_TURN_1,
    .board = {
      {SQUARE_STATUS_EMPTY, SQUARE_STATUS_EMPTY, SQUARE_STATUS_EMPTY},
      {SQUARE_STATUS_EMPTY, SQUARE_STATUS_EMPTY, SQUARE_STATUS_EMPTY},
      {SQUARE_STATUS_EMPTY, SQUARE_STATUS_EMPTY, SQUARE_STATUS_EMPTY}
    },
    .userResponse = USER_RESPONSE_SUCCESS
  };

  return game;
}
