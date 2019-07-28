#include "inventory.h"

Inventory::Inventory(float weightMax) : _WeightMax(weightMax), _WeightCurrent(0)
{

}

AddToInventoryStatus Inventory::addItemToInventory(Item * item)
{
    if ( item->getWeight() + _WeightCurrent > _WeightMax)
    {
        return AddToInventoryStatus::NO_SPACE;
    }

    _WeightCurrent += item->getWeight();
    _InventoryList.append(item);
    return AddToInventoryStatus::SUCCESS;
}

EquipReturnCode Inventory::equipMainWeapon(ItemWeapon * weapon)
{
    // if nothing was equipped
    if ( _Equipped.hand == WeaponHands::None)
    {
        _Equipped.weaponMain = weapon;
        _Equipped.hand = weapon->getHands() == 1 ? WeaponHands::Main :   WeaponHands::TwoHanded;
        weapon->setEquipped(true);
        return EquipReturnCode::SUCCESS;
    }
    // if equipped main weapon or twohanded
    if ( _Equipped.hand == WeaponHands::Main || _Equipped.hand == WeaponHands::TwoHanded)
    {
        _Equipped.weaponMain->setEquipped(false);
        _Equipped.weaponMain = weapon;
        _Equipped.hand = weapon->getHands() == 1 ? WeaponHands::Main :   WeaponHands::TwoHanded;
        weapon->setEquipped(true);
        return EquipReturnCode::SUCCESS;
    }
    // if equipped both
    if ( _Equipped.hand == WeaponHands::Both )
    {
         if ( weapon->getHands() == 1)
         {
             _Equipped.weaponMain->setEquipped(false);
             _Equipped.weaponMain = weapon;
             weapon->setEquipped(true);
             return EquipReturnCode::SUCCESS;
         }
         if ( weapon->getHands() == 2)
         {
             _Equipped.weaponMain->setEquipped(false);
             _Equipped.weaponSecond->setEquipped(false);
             _Equipped.weaponSecond = nullptr;
             _Equipped.weaponMain = weapon;
             _Equipped.hand = WeaponHands::TwoHanded;
             weapon->setEquipped(true);
            return EquipReturnCode::SUCCESS;
         }
    }

    return  EquipReturnCode::Other;
}

EquipReturnCode Inventory::equipSecondWeapon(ItemWeapon * weapon)
{
    // one handed
    if ( weapon->getHands() == 1 )
    {
        // if nothing was equipped
        if ( _Equipped.hand == WeaponHands::None)
        {
            _Equipped.weaponSecond = weapon;
            _Equipped.hand = WeaponHands::Second;
            weapon->setEquipped(true);
            return EquipReturnCode::SUCCESS;
        }
        // if second weapon definitely equipped
        if ( _Equipped.hand == WeaponHands::Both || _Equipped.hand == WeaponHands::Second )
        {
            _Equipped.weaponSecond->setEquipped(false);
            _Equipped.weaponSecond = weapon;
            weapon->setEquipped(true);
            return EquipReturnCode::SUCCESS;
        }

    }
    // two handed
    else
    {
        if ( _Equipped.weaponSecond != nullptr)
        {
            _Equipped.weaponSecond->setEquipped(false);
            _Equipped.weaponSecond = nullptr;
        }
        if ( _Equipped.weaponMain != nullptr)
        {
            _Equipped.weaponMain->setEquipped(false);
            _Equipped.weaponMain = nullptr;
        }

        _Equipped.weaponMain = weapon;
        _Equipped.hand = WeaponHands::TwoHanded;
        weapon->setEquipped(true);
        return EquipReturnCode::SUCCESS;

    }

    return  EquipReturnCode::Other;
}
