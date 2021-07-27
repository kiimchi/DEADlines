//
// Created by student on 2/2/20.
//

#ifndef DEADLINES_KOBIETA_H
#define DEADLINES_KOBIETA_H


#include "Character.h"

class Kobieta : public Character{
public:
    Kobieta(int x, int y,int live);
    ~Kobieta();
private:
    bool Powerup;

};


#endif //DEADLINES_KOBIETA_H
