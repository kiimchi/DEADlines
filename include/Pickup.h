//
// Created by student on 2/1/20.
//

#ifndef DEADLINES_PICKUP_H
#define DEADLINES_PICKUP_H
#include "SDL.h"
#include "SDL_image.h"

#include "TextureMenager.h"

class Pickup {
public:

    Pickup(int dx,int dy);
    virtual ~Pickup();
    virtual void DrawPickup()=0;
    virtual int isBeingEaten()=0;


    SDL_Rect getSrc();
    SDL_Rect getDest();

    bool isEaten() const;

    void setEaten(bool eaten);


private:

    SDL_Rect src, dest;
int x,y;
bool Eaten;

};


#endif //DEADLINES_PICKUP_H
