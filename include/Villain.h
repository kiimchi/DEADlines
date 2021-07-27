#ifndef DEADLINES_VILLAIN_H
#define DEADLINES_VILLAIN_H
#include "SDL.h"
#include "SDL_image.h"

#include "TextureMenager.h"

class Villain{
public:

    Villain(int x, int y ,int end);
    virtual ~Villain();

    virtual void moves()= 0;
    virtual void DrawVillain()=0;



    int getDx() const;
    int getDy() const;
    bool isCount() const;
    void setDx(int dx);
    void setDy(int dy);


    int getFinalx() const;
    int getStartx() const;
    void setCount(bool count);


    void setDest( SDL_Rect dest);

    SDL_Rect getDest();
    SDL_Rect getSrc();

    void setStarty(int starty);

    int getStarty() const;

    bool isDeadly() const;

    void setDeadly(bool deadly);


private:


    bool deadly;
    int dx,dy;
    int finalx,starty,startx;
    bool count;
    SDL_Rect src, dest;


};
#endif //DEADLINES_VILLAIN_H
