#ifndef FIGHT_H
#define FIGHT_H

#include "player/player.h"
#include "monsters/monster.h"

class Fight
{

private:
    Player * _Player;   // pointer to Player
    Monster * _Monster; // pointer to Monster
    int _TurnId;        // number of current turn
public:
    Fight(Player * player, Monster * monster);
    void Turn();
};

#endif // FIGHT_H
