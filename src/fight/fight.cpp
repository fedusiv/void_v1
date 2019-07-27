#include "fight.h"

Fight::Fight(Player *player, Monster *monster)
{
    _Player = player;
    _Monster = monster;
    _TurnId = 1;

    connect(player, &Player::playerMakeWeaponHit, this, &Fight::onPlayerMakeWeaponHit);
}

// Called when Player devided to make weapon hit
void Fight::onPlayerMakeWeaponHit(SkillAttackResult * attack)
{
    if ( _Monster->defencePhaseFromWeaponHit(attack) == FighterLiveStatus::Life )
    {
        monsterPhase(); // now monster attack
    }
    else
    {
        endMosnterDead();// mosnter dead
    }

}

void Fight::monsterPhase()
{

}

void Fight::endMosnterDead()
{

}
