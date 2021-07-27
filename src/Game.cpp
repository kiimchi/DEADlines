//
// Created by student on 1/21/20.
//

#include <Kobieta.h>

#include <Julek.h>
#include "Game.h"
#include "Gameboard.h"
#include "Character.h"
#include "Massage.h"

Gameboard* gameboard;
Character* player;
Massage* massage;
Massage* massage2;

SDL_Renderer* Game::renderer = nullptr;


Game::Game() { };

Game::~Game() {};

void Game::initate(int width, int height, bool fullscreen,int character) {

    int flags = 0;

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow("DEADlines", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
       if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0, 51, 102, 255);
        }

        isRunning = true;
    }



    gameboard = new Gameboard();
    massage=new Massage(96,0);

    massage2=new Massage(640,0);
    if(character==1)
    player= new Kobieta(1*32,1*32,5);

    if(character==2)

        player= new Julek(32,32,8);
    std::cout<<player->getLives();
    massage->MassageChange(player->getLives());
}

void Game::handleEvents() {


    SDL_Event event;
    SDL_PollEvent(&event);

    int key;

            switch (event.type)
            {
                case SDL_QUIT :
                    isRunning = false;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        case SDLK_RIGHT:
                            key=1;
                            break;
                        case SDLK_LEFT:
                            key=2;
                            break;
                        case SDLK_UP:
                            key=3;
                            break;
                        case SDLK_DOWN:
                            key=4;
                            break;
                        default:

                            break;
                    }

                    player->ChangePositionAndWall(gameboard,key);
                    break;
                case SDL_KEYUP:
                    break;
                default:
                    break;


            }
    switch(gameboard->isEating(player->getDX(),player->getDY())) {
        case 1:
            player->setEctsCounter(player->getEctsCounter() + 1);
            massage2->MassageChange(player->getEctsCounter());
            break;
        case 2:
            player->setCounter1(0);
            player->setVelocity(player->getVelocity()*2);
            break;

                case 3:
                    player->setCounter(0);
                    player->setImune(true);
                    break;
        default:
            break;
    }

  //  std::cout<<player->getLives()<<std::endl;

    if(gameboard->CrashControl(player->getDX(),player->getDY())&&!player->isInjured()&&!player->isImune()) {
        player->setLives(player->getLives() - 1);
            massage->MassageChange(player->getLives());
        if(player->getLives()==0) {
            massage->Gameover();
            isRunning = false;
        }
        player->setInjured(true);
    }


}

void Game::render() {
    SDL_RenderClear(renderer);
    gameboard->DrawMaze();
   player->DrawPlayer();
    gameboard->DrawVillains();
    gameboard->DrawPickups();
    massage->DrawMassage();
    massage2->DrawMassage();
        SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::updatePosition() {

gameboard->moveVillains();
player->move();

}