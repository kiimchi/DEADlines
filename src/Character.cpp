//
// Created by student on 1/21/20.
//

#include "Character.h"
int LevelChanger=1;


Character::Character(int x,int y) {
    person=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/player.png");
    hurt=TextureMenager::LoadTexture("/home/student/CLionProjects/local/zustyna/DEADlines/textures/hurt.png");
    dx=x;dy=y;
    ectsCounter=0;
    //lives=3;
   src.x=src.y=0;
    src.h=src.w=32;
    dest.x=x;
    dest.y=y;
    dest.h=dest.w=32;
    //velocity=8;

}
Character::~Character() {};

void Character::DrawPlayer() {
    if(!injured&&!imune)
    TextureMenager::Draw(person,src,dest);
    if(injured)
        TextureMenager::Draw(hurt,src,dest);
    if(imune)
        TextureMenager::Draw(hurt,src,dest);
}



void Character::ChangePositionAndWall(Gameboard* maze,int key) {

    if(key!=1&&key!=2&&key!=3&&key!=4)
        return;

 CanMove=false;
    int placex,placex2;
    int placey,placey2;
    if(key==1)    ///RIGHT
    {  dx+=velocity;
        if( dx%32>0)
            placex=(dx/32)+1;
        else
            placex=dx/32;
        placey=dy/32;
    }
    if(key==2)   ///LEFT
    {
        dx -= velocity;
        if (dx % 32 > 0)
            placex = (dx / 32);
        else
            placex = dx / 32 + 1;
        placey = dy / 32;

    }
    placex2=placex;
    placey2=placey;

    if(key==4)       ///DOWN
    {  dy+=velocity;

        if( dy%32>0)
            placey=(dy/32)+1;
        else
            placey=dy/32;
        placex=dx/32;

        if((dx)%32>10)
            placex2=(((dx)/32)+1);
        else
            placex2=((dx)/32);
        placey2=(((dy)/32));

    }


if(key==3)      ///UP
{  dy-=velocity;
if( dy%32>0)
placey=(dy/32);
else
placey=(dy/32)+1;
placex=dx/32;

if((dx+5)%32>16)
placex2=(((dx+5)/32)+1);
else
    placex2=((dx+5)/32);
placey2=(((dy)/32));

}
    if(maze->GetMazeTile(placex,placey)==2) {
        dx=x;
        dy=y;
        if(getEctsCounter()>=0)
        {dx = 32;
        dy = 32;
        x=32;
        y=32;
        dest.x = x;
        dest.y = y;
        setCounter(0);
        maze->CheckLevel();}

    }
    if(maze->GetMazeTile(placex,placey)==0)
    { CanMove=true;
        }
    if(maze->GetMazeTile(placex2,placey2)==1)
    { dx=x;
        dy=y;
    }
    if(maze->GetMazeTile(placex,placey)==1)
    {
        dx=x;
        dy=y;
    }


}


void Character::setCounter1(int counter1) {
    Character::counter1 = counter1;
}

int Character::getVelocity() const {
    return velocity;
}

void Character::move() {
  counter++;
  counter1++;
  if(counter==60)
      injured=false;
  if(counter==180)
      Character::setImune(false);
  if(counter1==180) {
      Character::setVelocity(Character::getVelocity()/2);

  }

    if(CanMove) {
        x = dx;
        y = dy;
        dest.x = x;
        dest.y = y;
        dy = y;
        dx = x;
        CanMove=false;
    }
}


int Character::getDX() const {
    return dx;
}

int Character::getDY() const {
    return dy;
}

int Character::getLives() const {
    return lives;
}

void Character::setLives(int lives) {

    Character::lives = lives;
}

void Character::setInjured(bool injured) {
    counter=0;
    Character::injured = injured;

}

bool Character::isInjured() const {
    return injured;
}

int Character::getEctsCounter() const {
    return ectsCounter;
}

bool Character::isImune() const {
    return imune;
}

void Character::setImune(bool imune) {
    Character::imune = imune;
}

void Character::setEctsCounter(int ectsCounter) {
    Character::ectsCounter = ectsCounter;
}

void Character::setVelocity(int velocity) {
    Character::velocity = velocity;
}

void Character::setCounter(int counter) {
    Character::counter = counter;
}
