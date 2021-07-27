//
// Created by student on 1/28/20.
//
#include "Villain.h"


Villain::Villain(int x, int y,int end) {
    deadly=true;
    starty=y;
    startx=x;
    finalx=end; count=true;
    dx=x;
    dy=y;
    src.x=src.y=0;
    src.h=src.w=32;
    dest.x=x;
    dest.y=y;
    dest.h=dest.w=32;
}

Villain::~Villain() {}


bool Villain::isDeadly() const {
    return deadly;
}

void Villain::setDeadly(bool deadly) {
    Villain::deadly = deadly;
}

SDL_Rect Villain::getSrc()  {
    return src;
}

 SDL_Rect Villain::getDest() {
    return dest;
}

//void Villain::DrawVillain() {}
//void Villain::move() {}

int Villain::getStarty() const {
    return starty;
}

int Villain::getFinalx() const {
    return finalx;
}

void Villain::setCount(bool count) {
    Villain::count = count;
}

int Villain::getStartx() const {
    return startx;
}

int Villain::getDx() const {
    return dx;
}

int Villain::getDy() const {
    return dy;
}

bool Villain::isCount() const {
    return count;
}

void Villain::setDx(int dx) {
    Villain::dx = dx;
}

void Villain::setDy(int dy) {
    Villain::dy = dy;
}

void Villain::setDest( SDL_Rect dest) {
   this->dest=dest;
}

