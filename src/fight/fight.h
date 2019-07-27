#ifndef FIGHT_H
#define FIGHT_H

#include "player/player.h"
#include "monsters/monster.h"
#include "skills/skillattack.h"
#include "return_codes.h"

class Fight : public QObject
{
    Q_OBJECT
private:
    Player * _Player;   // pointer to Player
    Monster * _Monster; // pointer to Monster
    int _TurnId;        // number of current turn
private slots:
    void onPlayerMakeWeaponHit(SkillAttackResult * attack);
    void monsterPhase();
    void endMosnterDead();
    void endPlayerDead();
public:
    Fight(Player * player, Monster * monster);

};

#endif // FIGHT_H
