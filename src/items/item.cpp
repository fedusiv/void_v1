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

ItemType Item::getEquipType()
{
    return _Attribute.Type;
}

EquipReturnCode Item::checkRequirments(int player_level, int **type_points)
{
    return EquipReturnCode::SUCCESS;
}


