TARGET = cpluspluslib
TEMPLATE = lib
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -Wl,--no-as-needed

unix
{
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/../build/debug
    } else {
        DESTDIR = $$PWD/../build/release
    }
}

SOURCES += \
    chronolib.cpp \
    threadlib.cpp \
    functionallib.cpp \
    algorithmlib.cpp

HEADERS += \
    chronolib.h \
    threadlib.h \
    functionallib.h \
    algorithmlib.h
