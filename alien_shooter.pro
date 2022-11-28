TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        enemyship.cpp \
        fastenemy.cpp \
        game.cpp \
        main.cpp \
        slowenemy.cpp \
        userShip.cpp

HEADERS += \
    enemyship.h \
    fastenemy.h \
    game.h \
    slowenemy.h \
    userShip.h
