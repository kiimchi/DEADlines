//
// Created by student on 2/1/20.
//

#include "Kawa.h"

Kawa::Kawa(int x, int y):Pickup(x,y){
}
Kawa::~Kawa() {}

void Kawa::DrawPickup() {
    TextureMenager::Draw(getTexture(),getSrc(),getDest());
}

int Kawa::isBeingEaten() {
 return 2;
}

SDL_Texture *Kawa::getTexture() {
    kawa= TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/kawa.png");//
    return kawa;
}
