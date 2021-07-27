//
// Created by student on 1/28/20.
//

#ifndef DEADLINES_DEADLINE_H
#define DEADLINES_DEADLINE_H

#include "Villain.h"

class DEADLINE :public Villain{
public:
     SDL_Texture * getTexture();
     void setTexture();
    DEADLINE(int x,int y,int end);
    void DrawVillain() override;
    void moves() override;
private:
    SDL_Texture* deadline;
};


#endif //DEADLINES_DEADLINE_H
