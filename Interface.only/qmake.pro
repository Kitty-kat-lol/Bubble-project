TEMPLATE     = vcapp
TARGET       = Final
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += Interface.h Options.h
SOURCES     += Interface.cpp Final.cpp Options.cpp
INCLUDEPATH += .
LIBS	      += 
QT += widgets
