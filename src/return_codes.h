#ifndef RETURN_CODES_H
#define RETURN_CODES_H


/*
 *  Header that holds enum or smth like with return code status
 */


// enum of return code, when received requst to equip equipment
enum class EquipReturnCode
{
    SUCCESS,        // success, equip or tke off equip
    LEVEL_ERROR,    // can not equip, level isnt enough
    STATS_ERROR    // can not equip, points isnt enough
};

#endif // RETURN_CODES_H
