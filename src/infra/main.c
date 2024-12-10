#include <stdio.h>

#include "../core/entities/game.h"
#include "../core/use_cases/startGameUseCase.h"
#include "../core/use_cases/checkSquareUseCase.h"
#include "./presentation/gameView.h"

int main() {
  struct Game game = startGameUseCase();
 
  while (game.status == GAME_STATUS_RUNNING) {
    showGame(&game);
    checkSquareUseCase(readUserInput(), &game);
  }

  showGame(&game);

  return 0;
}
