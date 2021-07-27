//
// Created by student on 2/2/20.
//

#include "Kobieta.h"

Kobieta::Kobieta(int x,int y,int live):Character(x,y) {
  Character::setLives(live);
  Character::setCounter(200);
  Character::setVelocity(4);
    person=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/girl.png");
    hurt=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/girlh.png");
}
Kobieta::~Kobieta() {}