//
// Created by student on 1/20/20.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <zconf.h>
#include "Game.h"
#include "Button.h"
#include "TextureMenager.h"


using namespace std;
Game *game = nullptr;
SDL_Window* screen =nullptr;
SDL_Renderer* rendere = nullptr;

Button* InstructionButton;
Button* Instruction;
Button* StartManButton;
Button* StartWomanButton;
Button* StartArturButton;
Button* QuitButton;
Button* Title;


int main()
{
    bool menu=true;
    const int FPS =60;
    const int frameDelay = 1000/FPS;
    Uint32 frameStart;
    int frameTime;

    screen=SDL_CreateWindow("DEADlines",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,800,640,false);
    rendere = SDL_CreateRenderer(screen, -1, 0);
    if (rendere)
    {
        SDL_SetRenderDrawColor(rendere, 0, 0, 0, 255);
    }

    if (screen == NULL){
        std::cout << "Can not open the game" << std::endl; //trycatche
        return 0;
    }



    InstructionButton=new Button(250,180,330,70,rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/instruction.png");
    StartWomanButton=new Button(210,300,96,96,rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/girl.png");
    StartManButton=new Button(350,300,96,96,rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/boyh.png");
    StartArturButton=new Button(500,300,96,96,rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/artur.png");
    QuitButton=new Button(335,500,140,80,rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/quit.png");
    Title= new Button(150,40,520,150,rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/title.png");
    Instruction=new Button(0,0,800,640,rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/title.png");

    int key=1;
    bool gamer=false;
int character;

do
{
    SDL_RenderClear(rendere);
    SDL_Event click;

    InstructionButton->UnChosenButton(rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/instruction.png");
    QuitButton->UnChosenButton(rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/quit.png");
    StartWomanButton->UnChosenButton(rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/girl.png");
    StartManButton->UnChosenButton(rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/boyh.png");
    StartArturButton->UnChosenButton(rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/artur.png");
    Instruction->UnChosenButton(rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/ininstruction.png");

    if(key==1)
    {InstructionButton->ChosenButton(rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/instructionc.png");
    }

    if(key==2){
        StartWomanButton->ChosenButton(rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/girlh.png");
    }

    if(key==3){

        StartManButton->ChosenButton(rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/boy.png");
    }

    if(key==4){

        StartArturButton->ChosenButton(rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/arturh.png");
        Instruction->ChosenButton(rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/arturmassage.png");
    }
    if(key==5){

        QuitButton->ChosenButton(rendere,"/home/student/CLionProjects/local/zustyna/DEADlines/textures/quitc.png");
    }

    SDL_RenderClear(rendere);


    Title->DrawButton(rendere);
    InstructionButton->DrawButton(rendere);
    StartManButton->DrawButton(rendere);
    StartArturButton->DrawButton(rendere);
    StartWomanButton->DrawButton(rendere);
    QuitButton->DrawButton(rendere);


    SDL_PollEvent(&click);
    switch (click.type) {
        case SDL_QUIT :
            SDL_DestroyWindow(screen);
            SDL_DestroyRenderer(rendere);
            SDL_Quit();
            menu=false;
            break;
        case SDL_KEYDOWN:
            switch (click.key.keysym.sym) {
                case SDLK_q:
                    key=1;
                    break;
                case SDLK_w:
                        key =2;
                    break;

                case SDLK_e:
                    key=3;
                    break;
                case SDLK_r:
                    key=4;
                    break;
                case SDLK_t:
                    key=5;
                    break;
                case SDLK_RETURN:
                    if (key == 1)
                    {
                        cout << "instruction" << endl;
                        SDL_RenderClear(rendere);

                        Instruction->DrawButton(rendere);
                        SDL_RenderPresent(rendere);
                        usleep(10000000);
                    }
                    if (key == 2) {
                        SDL_DestroyWindow(screen);
                        SDL_DestroyRenderer(rendere);
                        SDL_Quit();
                        gamer=true;
                        menu = false;
                        character=1;
                    }
                    if(key==3)
                    {
                        SDL_DestroyWindow(screen);
                        SDL_DestroyRenderer(rendere);
                        SDL_Quit();
                        gamer=true;
                        menu = false;
                        character=2;
                    }
                    if(key==4)
                    {

                        SDL_RenderClear(rendere);

                        Instruction->DrawButton(rendere);
                        SDL_RenderPresent(rendere);
                        usleep(3000000);
                    }
                    if(key==5)
                    {
                        SDL_DestroyWindow(screen);
                        SDL_DestroyRenderer(rendere);

                        menu = false;
                    }
                    break;
            }
            break;

        case SDL_KEYUP:
            break;
        default:
            break;



    }

    SDL_RenderPresent(rendere);
}
while(menu);

if (gamer) {
    game = new Game();
    game->initate(800, 640, false,character);


    while (game->running()) {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->updatePosition();
        game->render();


        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
}
    return 0;


}
