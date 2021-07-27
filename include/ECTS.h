//
// Created by student on 2/1/20.
//

#ifndef DEADLINES_ECTS_H
#define DEADLINES_ECTS_H


#include "Pickup.h"

class ECTS : public Pickup{
public:
    ECTS(int x,int y);
    ~ECTS();
    int isBeingEaten() override;
    void DrawPickup() override;
    SDL_Texture* getTexture();
private:
    SDL_Texture* ects;


};


#endif //DEADLINES_ECTS_H
