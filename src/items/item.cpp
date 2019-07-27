#include "item.h"


Item::Item(ItemAttribute attribute)
{
    _Attribute = attribute;
}

int Item::getLevel()
{
    return _Attribute.Level;
}

float Item::getWeight()
{
    return _Attribute.Weight;
}

QString Item::getName()
{
    return _Attribute.Name;
}

void Item::setName(QString name)
{
    _Attribute.Name = name;
}

QString Item::getDesc()
{
    return _Attribute.Desc;
}

bool Item::isEquipped()
{
    return _Equipped;
}

void Item::setEquipped(bool status)
{
    _Equipped = status;
}

ItemType Item::getItemType()
{
    return _Attribute.Type;
}

EquipReturnCode Item::checkRequirments(StatsRequire player_stats) //QUESTION: params should be MainStats + level, nope?..
{

    for (int stat = 0; stat < RequireStatsCount; stat++)
    {
        if(player_stats[stat] < _Attribute.Requirements[stat])
        {
            return stat == Level ? EquipReturnCode::LEVEL_ERROR : EquipReturnCode::STATS_ERROR;
        }
    }

    return EquipReturnCode::SUCCESS;
}

/*
 * @desc : return just empty values of damage
 * @return ItemWeaponDamage empty variable
 */
ItemWeaponDamage Item::getDamage()
{
    ItemWeaponDamage damage;
    damage.damage = 0;
    damage.Type = DamageTypes::DamageTypes_Count;
    return damage;
}

/*
 * @desc : return just empty values of armor
 * @return ItemClothArmor empty variable
 */
ItemClothArmor Item::getArmor()
{
    ItemClothArmor armor;
    armor.armor = 0;
    armor.Type = DamageTypes::DamageTypes_Count;
    return armor;
}


