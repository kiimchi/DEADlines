//
// Created by student on 1/28/20.
//

#ifndef DEADLINES_BEST_H
#define DEADLINES_BEST_H

#include "Villain.h"

class BEST: public Villain {
public:
    BEST(int x,int y,int end);
    SDL_Texture * getTexture();

    void DrawVillain() override;

    void moves() override ;
private:
    SDL_Texture* best;

};


#endif //DEADLINES_BEST_H
