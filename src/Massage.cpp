//
// Created by student on 2/1/20.
//

#include "Massage.h"

Massage::Massage(int x,int y) {
    massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/numbers/0.png");
    src.x=src.y=0;
    dest.x=x;
    dest.y=y;
    src.h=dest.h=32;
    src.w=dest.w=32;
}
Massage::~Massage() {}

void Massage::MassageChange(int number) {
    if(number==1)
    massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/numbers/1.png");
    if(number==2)
        massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/numbers/2.png");
    if(number==3)
        massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/numbers/3.png");
    if(number==4)
        massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/numbers/4.png");
    if(number==5)
        massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/numbers/5.png");
    if(number==6)
        massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/numbers/6.png");
    if(number==7)
        massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/numbers/7.png");
    if(number==8)
        massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/numbers/8.png");
    if(number==9)
        massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/numbers/9.png");
    if(number==10)
        massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/numbers/10.png");
    if(number==11)
        massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/numbers/11.png");
    if(number==12)
        massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/numbers/12.png");
    if(number==13)
        massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/numbers/13.png");
    if(number==14)
        massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/numbers/14.png");
    if(number==15)
        massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/numbers/15.png");
}

void Massage::Gameover() {
    massage=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/gameover.png");
    dest.x=224;
    dest.y=304;
    src.h=dest.h=96;
    src.w=dest.w=384;
}
void Massage::DrawMassage() {
    TextureMenager::Draw(massage,src,dest);
}