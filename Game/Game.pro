TEMPLATE     = vcapp
TARGET       = Interface
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += Acceuil.h Jeu.h Options.h Bulle_Custom.h Player_custom.h
SOURCES     += Acceuil.cpp Main.cpp Jeu.cpp Options.cpp Bulle_Custom.cpp Player_custom.cpp
INCLUDEPATH += .
LIBS	      += 
QT += widgets
QT += 3dquickscene2d
QT += 3dinput
QT += testlib
QT += gui
QT +=gamepad