TEMPLATE     = vcapp
TARGET       = Final
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += Interface.h Options.h Scores.h Play.h
SOURCES     += Interface.cpp Final.cpp Options.cpp Scores.cpp Play.cpp
INCLUDEPATH += .
LIBS	      += 
QT += widgets
