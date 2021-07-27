//
// Created by student on 2/2/20.
//

#include "Button.h"

Button::Button(int x,int y,int width,int heigth,SDL_Renderer* rendere,const char* filename) {
    src.x=src.y=0;
    src.w=dest.w=width;
    src.h=dest.h=heigth;
    dest.x=x;
    dest.y=y;

        SDL_Surface* tempSurface = IMG_Load(filename);
        SDL_Texture* tex = SDL_CreateTextureFromSurface(rendere,tempSurface);
        SDL_FreeSurface(tempSurface);
        button=tex;

}

Button::~Button() {}

void Button::ChosenButton(SDL_Renderer* rendere,const char* filename) {

    SDL_Surface* tempSurface = IMG_Load(filename);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rendere,tempSurface);
    SDL_FreeSurface(tempSurface);
    button=tex;

}

void Button::UnChosenButton(SDL_Renderer *rendere,const char* filename) {
   SDL_Surface* tempSurface = IMG_Load(filename);
        SDL_Texture* tex = SDL_CreateTextureFromSurface(rendere,tempSurface);
        SDL_FreeSurface(tempSurface);
        button=tex;

}

void Button::DrawButton( SDL_Renderer *rendere) {

    SDL_RenderCopy(rendere,button,&src,&dest);

}