#ifndef SKILLVALUES_H
#define SKILLVALUES_H

#include <stdint.h>
#include <QVector>

/*
 * This header stores information of different types
 * skill with different values
 * Skill values stores QVector with int, in case of ClassType it translate by rule
 */
class SkillValues
{
public:
    SkillValues(QVector<float> values, int classType, int lear)
    {
        Q_UNUSED(values);
        Q_UNUSED(classType);
        Q_UNUSED(lear);
    }


};

#endif // SKILLVALUES_H
