//
// Created by student on 1/21/20.
//

#ifndef DEADLINES_CHARACTER_H
#define DEADLINES_CHARACTER_H
#include "SDL.h"
#include "SDL_image.h"
#include "TextureMenager.h"
#include "Gameboard.h"

class Character {
public:

    Character(int x, int y );
    virtual~Character();


    void ChangePositionAndWall(Gameboard* maze ,int key);
    void move();
    void DrawPlayer();

    int getDX() const;

    int getDY() const;

    void setLives(int lives);

    int getLives() const;

    void setInjured(bool injured);

    bool isInjured() const;

    void setEctsCounter(int ectsCounter);

    int getEctsCounter() const;

    void setVelocity(int velocity);

    void setCounter(int counter);

    bool isImune() const;

    void setImune(bool imune);

    int getVelocity() const;



    void setCounter1(int counter1);

private:
    int ectsCounter;
    bool injured=false;
    bool CanMove;
    bool imune=false;
    int velocity;
int x;
int y;
int dx;
int dy;
int lives;

int counter;
int counter1=200;
protected:
    SDL_Rect src, dest;
    SDL_Texture* person;
    SDL_Texture* hurt;

};


#endif //DEADLINES_CHARACTER_H
