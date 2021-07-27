//
// Created by student on 1/21/20.
//

#ifndef DEADLINES_TEXTUREMENAGER_H
#define DEADLINES_TEXTUREMENAGER_H

#include <SDL_image.h>
#include <SDL.h>


#include "Game.h"

class TextureMenager {
public:


    static SDL_Texture * LoadTexture(const char* filename);


    static void Draw(SDL_Texture* tex, SDL_Rect src,SDL_Rect dest);

};


#endif //DEADLINES_TEXTUREMENAGER_H
