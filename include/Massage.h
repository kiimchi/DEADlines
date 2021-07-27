//
// Created by student on 2/1/20.
//

#ifndef DEADLINES_MASSAGE_H
#define DEADLINES_MASSAGE_H

#include "Game.h"
#include "TextureMenager.h"

class Massage {
public:
    Massage(int x,int y);
    ~Massage();
    void MassageChange(int number);
    void Gameover();
    void DrawMassage();
private:
    SDL_Rect src, dest;
    SDL_Texture* massage;
};


#endif //DEADLINES_MASSAGE_H
