#include "item.h"


Item::Item(ItemAttribute attribute)
{
    _Attribute = attribute;
}

int Item::getLevel()
{
    return _Attribute.level;
}

float Item::getWeight()
{
    return _Attribute.weight;
}

QString Item::getName()
{
    return _Attribute.name;
}

void Item::setName(QString name)
{
    _Attribute.name = name;
}

QString Item::getDesc()
{
    return _Attribute.desc;
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
    return _Attribute.type;
}

EquipReturnCode Item::checkRequirments(StatsRequire player_stats)
{

    for (int stat = 0; stat < RequireStatsCount; stat++)
    {
        if(player_stats[stat] < _Attribute.requirements[stat])
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


