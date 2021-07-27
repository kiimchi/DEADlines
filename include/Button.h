//
// Created by student on 2/2/20.
//

#ifndef DEADLINES_BUTTON_H
#define DEADLINES_BUTTON_H


#include <SDL.h>
#include "SDL_image.h"


class Button {
public:
    Button(int x,int y,int width,int heigth,SDL_Renderer* rendere,const char* filename);
    ~Button();
    void ChosenButton(SDL_Renderer* rendere,const char* filename);
    void DrawButton(SDL_Renderer* rendere);
    void UnChosenButton(SDL_Renderer* rendere,const char* filename);
private:
    SDL_Rect src,dest;
    SDL_Texture* button;


};


#endif //DEADLINES_BUTTON_H
