//
// Created by student on 1/28/20.
//

#include "DEADLINE.h"
SDL_Rect  destina;

DEADLINE::DEADLINE(int x, int y, int end):Villain(x, y, end) {


    std::cout<<"buu"<<std::endl;
    destina.h=destina.w=32;
    //deadline= TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/villain.png"); //nie mam pojecia dlaczego tak nie dziala


}
void DEADLINE::setTexture() {
    this->deadline= TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/deadline.png");
}
void DEADLINE::DrawVillain() {

    TextureMenager::Draw(getTexture(),getSrc(),getDest());
}
SDL_Texture* DEADLINE::getTexture() {

    //bardzo bym chciala zeby to sie dalo zrobic raz ale mnie wiem dlaczego nie dziala w konstruktorze jak uzywamy smart pointerow

    deadline= TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/deadline.png");//
    return deadline;
}
void DEADLINE::moves(){
    if(isCount() )
        setDx(getDx()+1);
    if(!isCount())
        setDx(getDx()-1);
    if(getDx()==getFinalx()||getDx()==getStartx()) {
        setCount(!(isCount()));
    }


    destina.x=getDx();
    destina.y=getDy();
    setDest(destina);




}