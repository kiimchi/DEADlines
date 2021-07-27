//
// Created by student on 2/1/20.
//

#ifndef DEADLINES_KAWA_H
#define DEADLINES_KAWA_H


#include "Pickup.h"

class Kawa : public Pickup{
public:
    Kawa(int x,int y);
    virtual ~Kawa();
    void DrawPickup() override;
    int isBeingEaten() override;
    SDL_Texture* getTexture();
private:
    SDL_Texture* kawa;


};


#endif //DEADLINES_KAWA_H
