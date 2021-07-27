//
// Created by student on 1/28/20.
//

#include "BEST.h"

SDL_Rect  destin;
BEST::BEST(int x, int y, int end):Villain(x, y, end) {
    destin.h=destin.w=32;
    //best= TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/villain1.png");
}


void BEST::DrawVillain() {
    TextureMenager::Draw(getTexture(),getSrc(),getDest());
}
SDL_Texture* BEST::getTexture() {

    //bardzo bym chciala zeby to sie dalo zrobic raz ale mnie wiem dlaczego nie dziala w konstruktorze jak uzywamy smart pointerow

    best= TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/best.png");//
    return best;
}
void BEST::moves() {
    if(isCount() )
        setDy(getDy()+1);
    if(!isCount())
        setDy(getDy()-1);
    if(getDy()==getFinalx()||getDy()==getStarty()) {
        setCount(!(isCount()));
    }
    destin.x=getDx();
    destin.y=getDy();
    setDest(destin);
}