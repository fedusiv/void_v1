#ifndef PLAYER_H
#define PLAYER_H

#include "playerstate.h"
#include "skills/skilllist.h"
#include "skills/skillsqueue.h"
#include "skills/skillattack.h"
#include "common_types.h"
/*
 * Class Player. It is all data about current player
 */

class Player : public QObject
{
      Q_OBJECT
private:
    PlayerState * _PlayerState;     // pointer to object of Player's State
    // PlayerInventory
    SkillList * _PlayerSkillsList;  // pointer to List with all list, that player has
    SkillsQueue *_PlayerSkillQueue; // pointer to queue of Skills

public:
    Player();
    void MakeWeaponHit(WeaponHands hand); // decision of Player from GUI to make just hit by weapon

signals:
    void playerMakeWeaponHit(SkillAttackResult * attack);
};

#endif // PLAYER_H
