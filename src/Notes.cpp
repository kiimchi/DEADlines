//
// Created by student on 2/2/20.
//

#include "Notes.h"

Notes::Notes(int x, int y) :Pickup(x,y){

}
Notes::~Notes() {}


void Notes::DrawPickup() {
    TextureMenager::Draw(getTexture(),getSrc(),getDest());
}

int Notes::isBeingEaten() {
    return 3;
}

SDL_Texture *Notes::getTexture() {
    notes= TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/notes.png");
    return notes;
}
