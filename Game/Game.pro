TEMPLATE     = vcapp
TARGET       = Game
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += Bulle_Custom.h Player_custom.h
SOURCES     += Main.cpp Jeu.cpp Bulle_Custom.cpp Player_custom.cpp
INCLUDEPATH += .
LIBS	      += 
QT += widgets
QT += 3dquickscene2d
QT += 3dinput
QT += testlib
QT += gui
QT +=gamepad
