#include "item.h"


Item::Item(ItemAttribute attribute)
{

}

int Item::getLevel()
{
    return _Level;
}

float Item::getWeight()
{
    return _Weight;
}

QString Item::getName()
{
    return _Name;
}

void Item::setName(QString name)
{
    _Name = name;
}

QString Item::getInfo()
{
    return _Info;
}

QString Item::getDesc()
{
    return _Desc;
}

bool Item::isEquipped()
{
    return _Equipped;
}

void Item::setEquipped(bool status)
{
    _Equipped = status;
}

ItemType Item::getEquipType()
{
    return _Type;
}

EquipReturnCode Item::checkRequirments(int player_level, int **type_points)
{
    return EquipReturnCode::SUCCESS;
}

int * Item::getRequirments()
{
    return _RequiredPoints;
}


