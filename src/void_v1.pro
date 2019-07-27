QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        db/dbmanager.cpp \
    fight/fight.cpp \
        gamemanager.cpp \
        gui/gamegui.cpp \
        main.cpp \
    monsters/monster.cpp \
        player/player.cpp \
        player/playerstate.cpp \
        skills/skill.cpp \
    skills/skill_defence.cpp \
    skills/skillattack.cpp \
        skills/skilllist.cpp \
        skills/skillsqueue.cpp \
        items/item.cpp \
        items/itembelt.cpp \
        items/itemcloth.cpp \
        items/itemusable.cpp \
        items/itemweapon.cpp \ \
    skills/skillweaponhit.cpp

RESOURCES += qml/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    common_types.h \
    db/dbmanager.h \
    fight/fight.h \
    gamemanager.h \
    gui/gamegui.h \
    monsters/monster.h \
    player/player.h \
    player/playerstate.h \
    skills/skill.h \
    skills/skill_class_types.h \
    skills/skill_defence.h \
    skills/skillattack.h \
    skills/skilllist.h \
    skills/skills_description.h \
    skills/skillsqueue.h \
    skills/skillvalues.h \
    items/item.h \
    items/itembelt.h \
    items/itemcloth.h \
    items/itemusable.h \
    items/itemweapon.h \
    return_codes.h \
    skills/skillweaponhit.h
