TARGET = cplusplus11
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -Wl,--no-as-needed

INCLUDEPATH += \
    $$PWD/../cpluspluslib

unix
{
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/../build/debug
        LIBS += -L$$PWD/../build/debug
    } else {
        DESTDIR = $$PWD/../build/release
        LIBS += -L$$PWD/../build/release
    }
}

SOURCES += main.cpp

LIBS += \
    -lcpluspluslib \
    -pthread
