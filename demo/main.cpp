#include "game.h"
#include <SDL2/SDL.h>
#include <iostream>

// screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;

Game* game = nullptr;

int main(int argc, char* argv[]) {
    // fps limiter
    const int fps = 60;
    const int frameDelay = 1000 / fps;
    int frameStart;
    int frameTime;

    game = new Game();
    game->Init("map_test",
               SDL_WINDOWPOS_CENTERED,
               SDL_WINDOWPOS_CENTERED,
               SCREEN_WIDTH,
               SCREEN_HEIGHT,
               false);

    while (game->Running()) {
        frameStart = SDL_GetTicks(); // start chrono

        game->HandleEvents();
        game->Update();
        game->Render();

        frameTime = SDL_GetTicks() - frameStart; //end chrono

        if (frameDelay > frameTime) // delay if game runs too fast
            SDL_Delay(frameDelay - frameTime);
    }

    game->Clean();
    return 0;
}
