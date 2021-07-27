//
// Created by student on 2/2/20.
//

#ifndef DEADLINES_NOTES_H
#define DEADLINES_NOTES_H


#include "Pickup.h"

class Notes : public Pickup{
public:
Notes(int x,int y);
~Notes();
    void DrawPickup() override;
    int isBeingEaten() override;
    SDL_Texture* getTexture();
private:
SDL_Texture* notes;
};


#endif //DEADLINES_NOTES_H
