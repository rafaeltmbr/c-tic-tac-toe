#include <stdio.h>

#include "../core/entities/game.h"
#include "../core/entities/square.h"
#include "../core/use_cases/playerUseCases.h"
#include "./presentation/gameView.h"

int main() {
  struct Game game = {
    .status = GAME_STATUS_RUNNING,
    .playerTurn = PLAYER_TURN_1,
    .board = {
      {SQUARE_STATUS_EMPTY, SQUARE_STATUS_EMPTY, SQUARE_STATUS_EMPTY},
      {SQUARE_STATUS_EMPTY, SQUARE_STATUS_EMPTY, SQUARE_STATUS_EMPTY},
      {SQUARE_STATUS_EMPTY, SQUARE_STATUS_EMPTY, SQUARE_STATUS_EMPTY}
    },
    .userAction = USER_ACTION_SUCCESS
  };
  
  while (game.status == GAME_STATUS_RUNNING) {
    showGame(game);
    checkSquareUseCase(readUserInput(), &game);
  }

  showGame(game);

  return 0;
}
