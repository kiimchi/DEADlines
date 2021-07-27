//
// Created by student on 2/1/20.
//

#include "Pickup.h"

Pickup::Pickup(int x, int y) {

Eaten=false;
    src.x=src.y=0;
    src.h=src.w=32;
    dest.x=x;
    dest.y=y;
    dest.h=dest.w=32;
}
Pickup::~Pickup() {

}

void Pickup::setEaten(bool eaten) {
    Eaten = eaten;
}

SDL_Rect Pickup::getSrc()  {
    return src;
}
SDL_Rect Pickup::getDest()  {
    return dest;
}

bool Pickup::isEaten() const {
    return Eaten;
}
