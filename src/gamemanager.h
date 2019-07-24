#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <gui/gamegui.h>
#include "player/player.h"

class GameManager
{
public:
    GameManager();

private:
    GameGui _gui;
    Player _Player;
};

#endif // GAMEMANAGER_H
