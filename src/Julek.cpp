//
// Created by student on 2/2/20.
//

#include "Julek.h"
Julek::Julek(int x, int y, int velocity) :Character(x,y){
    Character::setVelocity(velocity);
    Character::setLives(3);
    Character::setCounter(200);
    person=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/boyh.png");
    hurt=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/boy.png");
}
Julek::~Julek() {}