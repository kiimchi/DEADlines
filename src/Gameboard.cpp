//
// Created by student on 1/21/20.
//

#include "Gameboard.h"
#include <iostream>
#include <ECTS.h>
#include <Kawa.h>
#include <Notes.h>



Gameboard::Gameboard() {

    path =TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/path.png");
    wall =TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/wall.png");
    portal =TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/portal.png");
    level=1;
    LoadMaze(level);

    src.x=src.y=0;
    src.h=src.w=32;
    dest.x=dest.y=0;
    dest.h=dest.w=32;

}

Gameboard::~Gameboard() {}




void Gameboard::AddVillain(std::shared_ptr<Villain> villain) {

    villains.push_back(villain);
}


void Gameboard::moveVillains() {

    for(int i=0;i<villains.size();++i){
        villains.at(i)->moves();
    }

}

void Gameboard::DrawVillains() {
    for(int i=0;i<villains.size();++i){

        villains.at(i)->DrawVillain();
    }

}

bool Gameboard::CrashControl(int dx, int dy) {
bool crash=false;



    for(int i=0;i<villains.size();++i){
        if(villains.at(i)->isDeadly())
        if(villains.at(i)->getDx()<=(dx+32)&&villains.at(i)->getDx()>=dx)
        if(villains.at(i)->getDy()==dy) {
            crash = true;
           // villains.at(i)->setDeadly(false);

        }
    }

    return crash;
}

void Gameboard::LoadVillains(int changer) {
    if(changer==1)
    {std::shared_ptr<Pickup> P1 = std::make_shared<ECTS>(384,32);
        std::shared_ptr<Pickup> P2 = std::make_shared<ECTS>(736,32);
        std::shared_ptr<Pickup> P3 = std::make_shared<ECTS>(320,96);
        std::shared_ptr<Pickup> P4 = std::make_shared<ECTS>(384,32);
        std::shared_ptr<Pickup> P5 = std::make_shared<ECTS>(512,96);
        std::shared_ptr<Pickup> P6 = std::make_shared<ECTS>(224,224);
        std::shared_ptr<Pickup> P7 = std::make_shared<ECTS>(32,320);
        std::shared_ptr<Pickup> P8 = std::make_shared<ECTS>(32,384);
        std::shared_ptr<Pickup> P9 = std::make_shared<ECTS>(32,576);
        std::shared_ptr<Pickup> P10 = std::make_shared<ECTS>(6*32,576);
        std::shared_ptr<Pickup> P11 = std::make_shared<ECTS>(320,576);
        std::shared_ptr<Pickup> P12 = std::make_shared<ECTS>(32*13,32*16);
        std::shared_ptr<Pickup> P13 = std::make_shared<ECTS>(32*13,32*14);
        std::shared_ptr<Pickup> P14 = std::make_shared<ECTS>(32*19,32*14);
        std::shared_ptr<Pickup> P15 = std::make_shared<ECTS>(32*23,32*10);
        std::shared_ptr<Pickup> K1 = std::make_shared<Kawa>(384,192);
        std::shared_ptr<Pickup> K2 = std::make_shared<Kawa>(6*32,32*13);
        std::shared_ptr<Pickup> N1 = std::make_shared<Notes>(18*32,32*8);
        std::shared_ptr<Pickup> N2 = std::make_shared<Notes>(6*32,32*5);
        std::shared_ptr<Villain> D1 = std::make_shared<DEADLINE>(320,224,512);
        std::shared_ptr<Villain> D2 = std::make_shared<DEADLINE>(256,160,320);
        std::shared_ptr<Villain> D3 = std::make_shared<DEADLINE>(608,192,672);
        std::shared_ptr<Villain> D4 = std::make_shared<DEADLINE>(96,224,160);
        std::shared_ptr<Villain> D5 = std::make_shared<DEADLINE>(416,384,480);
        std::shared_ptr<Villain> D6 = std::make_shared<DEADLINE>(96,512,256);
        std::shared_ptr<Villain> B2 = std::make_shared<BEST>(256,416,576);

        AddVillain(D1);AddVillain(D2);
        AddVillain(D3);
        AddVillain(D4);
        AddVillain(D5);
        AddVillain(D6);
        AddVillain(B2);
        AddPickup(P1);AddPickup(P2);AddPickup(P3);
        AddPickup(P4);AddPickup(P5);AddPickup(P6);
        AddPickup(P7);AddPickup(P8);AddPickup(P9);
        AddPickup(P11);AddPickup(P10);AddPickup(P12);
        AddPickup(P13);AddPickup(P14);AddPickup(P15);
        AddPickup(K1);AddPickup(K2);
        AddPickup(N1);AddPickup(N2);
    }
    if(changer==2)
    {
        std::shared_ptr<Pickup> P1 = std::make_shared<ECTS>(23*32,32);
        std::shared_ptr<Pickup> P2 = std::make_shared<ECTS>(32,32*3);
        std::shared_ptr<Pickup> P3 = std::make_shared<ECTS>(32*6,32*5);
        std::shared_ptr<Pickup> P4 = std::make_shared<ECTS>(32*10,5*32);
        std::shared_ptr<Pickup> P5 = std::make_shared<ECTS>(18*32,32*5);
        std::shared_ptr<Pickup> P6 = std::make_shared<ECTS>(3*32,6*32);
        std::shared_ptr<Pickup> P7 = std::make_shared<ECTS>(32*7,32*7);
        std::shared_ptr<Pickup> P8 = std::make_shared<ECTS>(32*10,32*7);
        std::shared_ptr<Pickup> P9 = std::make_shared<ECTS>(32*23,32*18);
        std::shared_ptr<Pickup> P10 = std::make_shared<ECTS>(32*11,32*18);
        std::shared_ptr<Pickup> P11 = std::make_shared<ECTS>(32*19,32*9);
        std::shared_ptr<Pickup> P12 = std::make_shared<ECTS>(32*4,32*11);
        std::shared_ptr<Pickup> P13 = std::make_shared<ECTS>(32*7,32*18);
        std::shared_ptr<Pickup> P14 = std::make_shared<ECTS>(32*23,32*18);
        std::shared_ptr<Pickup> P15 = std::make_shared<ECTS>(32*23,32*13);
        std::shared_ptr<Pickup> K1 = std::make_shared<Kawa>(32*3,32*4);
        //std::shared_ptr<Pickup> K2 = std::make_shared<Kawa>(6*32,32*13);
        //std::shared_ptr<Pickup> N1 = std::make_shared<Notes>(18*32,32*8);
        std::shared_ptr<Pickup> N2 = std::make_shared<Notes>(4*32,32*14);
        std::shared_ptr<Villain> D1 = std::make_shared<DEADLINE>(32*1,32*9,32*3);
        std::shared_ptr<Villain> D2 = std::make_shared<DEADLINE>(32*21,32*4,32*23);
        std::shared_ptr<Villain> D3 = std::make_shared<DEADLINE>(32*14,32*16,32*23);
        std::shared_ptr<Villain> B1 = std::make_shared<BEST>(21*32,32*14,32*18);
        std::shared_ptr<Villain> B2 = std::make_shared<BEST>(32*12,32*4,32*7);
        std::shared_ptr<Villain> D4 = std::make_shared<DEADLINE>(32*11,32*12,32*15);
        std::shared_ptr<Villain> B3 = std::make_shared<BEST>(32,32*12,32*18);

        AddVillain(D1);AddVillain(D2);AddVillain(D3);
        AddVillain(B1);AddVillain(B2);AddVillain(B3);
        AddVillain(D4);
        AddPickup(P1);AddPickup(P2);AddPickup(P3);
        AddPickup(P4);AddPickup(P5);AddPickup(P6);
        AddPickup(P11);AddPickup(P10);AddPickup(P12);
        AddPickup(P13);AddPickup(P14);AddPickup(P15);
        AddPickup(N2);AddPickup(K1);
    }

}

 void Gameboard::LoadMaze(int changer) {




     int level1[20][25]={
             {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
             {1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1},
             {1,0,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0,1,0,1},
             {1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1},
             {1,1,1,1,1,0,1,1,0,1,1,1,0,1,0,1,1,1,1,0,1,0,0,0,1},
             {1,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,1,1,0,1},
             {1,0,1,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,0,0,0,1,0,1},
             {1,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,1,0,1},
             {1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,1},
             {1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1},
             {1,0,1,0,1,1,0,1,1,0,1,1,1,1,1,0,0,0,1,0,1,0,1,0,1},
             {1,1,1,0,0,1,0,0,0,0,1,0,0,0,1,1,1,1,1,0,1,0,1,0,1},
             {1,0,1,1,0,1,1,1,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1},
             {1,0,1,0,0,0,0,1,0,0,0,0,1,0,1,1,1,0,1,1,1,1,1,0,1},
             {1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,0,0,0,1,0,0,0,1,0,1},
             {1,0,0,0,0,1,0,1,0,1,0,0,1,1,1,0,1,0,1,0,1,0,0,0,1},
             {1,1,1,0,0,0,0,0,0,1,1,0,1,0,0,0,1,0,0,0,1,1,1,1,1},
             {1,0,0,0,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,1,1},
             {1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
             {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
     int level2[20][25]={
             {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
             {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
             {1,1,1,0,1,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,1,0,1,0,1},
             {1,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1},
             {1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,0,1,0,0,0,1},
             {1,0,1,1,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,1,1,0,1},
             {1,0,1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,0,0,1,0,1},
             {1,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1},
             {1,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1},
             {1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1},
             {1,0,0,0,1,1,0,1,1,0,1,1,0,1,1,0,0,0,1,1,1,0,1,0,1},
             {1,1,1,0,0,1,0,0,0,0,1,0,0,0,1,1,1,0,1,0,0,0,1,0,1},
             {1,0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
             {1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,0,1},
             {1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1},
             {1,0,1,1,1,1,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
             {1,0,1,0,0,0,0,1,0,0,1,2,1,0,0,0,0,0,0,0,0,0,0,0,1},
             {1,0,1,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1},
             {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
             {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
     int arr[20][25];

     switch(changer)
     {
         case 1:



             for(int row=0;row<20;row++) {
                 for (int column = 0; column < 25; column++) {
                     arr[row][column] = level1[row][column];
                 }
             }



             break;

         case 2:
             villains.clear();
             pickups.clear();

             for(int row=0;row<20;row++) {
                 for (int column = 0; column < 25; column++) {
                     arr[row][column] = level2[row][column];
                 }
             }
             break;

         case 3:

             break;
     }

             for(int row=0;row<20;row++)
        {
       for(int column = 0;column<25;column++)
        {
           maze[row][column]=arr[row][column];
       }
        }
     LoadVillains(changer);

}

int Gameboard::GetMazeTile(int x, int y) {
    return maze[y][x];
}

void Gameboard::DrawMaze() {
    int type=0;
    for(int row=0;row<20;row++)
    {
        for(int column = 0;column<25;column++)
        {
            type = maze[row][column];
            dest.x=column*32;
            dest.y=row*32;
            switch(type)
            {
                case 0:
                    TextureMenager::Draw(path,src,dest);
                    break;
                case 1:
                    TextureMenager::Draw(wall,src,dest);
                    break;
                case 2:
                    TextureMenager::Draw(portal,src,dest);
                default:
                    break;
            }
        }
    }

}

int Gameboard::getLevel() const {
    return level;
}

void Gameboard::CheckLevel()
{
     level+=1;
        Gameboard::LoadMaze(level);


}

void Gameboard::DrawPickups() {

    for(int i=0;i<pickups.size();++i){
        pickups.at(i)->DrawPickup();
    }

}

void Gameboard::AddPickup(std::shared_ptr<Pickup> pickup) {

    pickups.push_back(pickup);
}


int Gameboard::isEating(int dx, int dy) {
    int eating=0;



    for(int i=0;i<pickups.size();++i){
        if(!pickups.at(i)->isEaten())
            if(pickups.at(i)->getDest().x<=(dx+28)&&pickups.at(i)->getDest().x>=dx)
                if(pickups.at(i)->getDest().y==dy) {
                    pickups.at(i)->setEaten(true);
                    eating = pickups.at(i)->isBeingEaten();

                    pickups.erase(pickups.begin()+i);

                }
    }

    return eating;
}
