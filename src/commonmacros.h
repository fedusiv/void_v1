#ifndef COMMONMACROS_H
#define COMMONMACROS_H

/*
 * getting size of staticly allocated c-style array
 * needed when you dont specify actual size of an array,
 * for eample: int values[] = {1, 2, 3, 4};
 * so if you resize array later rhis macro allow to automatically recalculate it's size
 */
#define SIZE_OF_ARRAY(a) sizeof(a) / sizeof(a[0])

/*
 * for cast enum classes to int
 */
#define INT(n) static_cast<int>(n)


//GAME INFO:

/*
 * sets max item's level
 * this must be defined for json parsing purposes
 */
#define MAX_ITEM_LEVEL 20 // TODO: maybe app should read this from config file?..

/*
 * paths to dirs with json data relative to .exe
 */
#define JSON_PATH QString("../../data/json/")
#define JSON_ITEMS_DIR QString("items/")
#define JSON_SKILLS_DIR QString("skills/")
#define JSON_MOBS_DIR QString("mobs/")

#endif //COMMONMACROS_H
