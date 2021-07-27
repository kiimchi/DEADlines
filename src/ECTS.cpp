//
// Created by student on 2/1/20.
//

#include "ECTS.h"

ECTS::ECTS(int x, int y):Pickup(x,y) {
   ects=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/ects.png");
}
ECTS::~ECTS() {}

void ECTS::DrawPickup() {

    TextureMenager::Draw(getTexture(),getSrc(),getDest());
}

int ECTS::isBeingEaten() {
return 1;
}
SDL_Texture* ECTS::getTexture() {



    ects= TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/ects.png");//
    return ects;
}