TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -Wl,--no-as-needed

unix
{
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/build/debug
    } else {
        DESTDIR = $$PWD/build/release
    }
}

SOURCES += main.cpp \
    chronolib.cpp \
    threadlib.cpp

HEADERS += \
    chronolib.h \
    threadlib.h

LIBS += -pthread
