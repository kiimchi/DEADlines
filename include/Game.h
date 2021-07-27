//
// Created by student on 1/21/20.
//

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>


#ifndef DEADLINES_GAME_H
#define DEADLINES_GAME_H


class Game
{
public:
    Game();
    ~Game();

    void initate(int width, int height, bool fullscreen,int character);

    void handleEvents();
    void updatePosition();
    bool running() { return isRunning; }
    void render();
    void clean();

    static SDL_Renderer *renderer;

private:
    int key;
    bool isRunning = false;
    int cnt = 0;
    SDL_Window *window;
};



#endif //DEADLINES_GAME_H
