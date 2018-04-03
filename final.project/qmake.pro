TEMPLATE     = vcapp
TARGET       = Final
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += Interface.h Arrow.h Bulle.h canb2usbconsolehlp.h CommunicationFPGA.h Coordonne.h Frame.h Player.h Registres.h
SOURCES     += Interface.cpp Arrow.cpp Bulle.cpp Frame.cpp Player.cpp Logic_test.cpp
INCLUDEPATH += .
LIBS	      += CommunicationFPGA.lib
QT += widgets
