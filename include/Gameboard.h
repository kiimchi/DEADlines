//
// Created by student on 1/21/20.
//

#ifndef DEADLINES_GAMEBOARD_H
#define DEADLINES_GAMEBOARD_H

#include "Villain.h"
#include "DEADLINE.h"
#include "BEST.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Pickup.h"
#include "TextureMenager.h"
#include <vector>
#include <memory>


class Gameboard {
private:

int level;
    std::vector<std::shared_ptr<Villain>>villains;
    std::vector<std::shared_ptr<Pickup>>pickups;

    SDL_Rect src, dest;

    SDL_Texture* portal;
    SDL_Texture* path;
    SDL_Texture* wall;

    int maze[20][25];

public:
Gameboard();
~Gameboard();
bool CrashControl(int dx,int dy);
void moveVillains();
void LoadMaze(int changer);
    void LoadVillains(int changer);
void DrawVillains();
void DrawPickups();
void AddPickup(std::shared_ptr<Pickup> pickup);

void AddVillain(std::shared_ptr<Villain> villain);
void DrawMaze();
 int GetMazeTile(int x, int y);

void CheckLevel();

    int isEating(int dx, int dy);

    int getLevel() const;
};


#endif //DEADLINES_GAMEBOARD_H
