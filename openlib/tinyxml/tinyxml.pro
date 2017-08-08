TARGET = tinyxmllib
TEMPLATE = lib
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

unix
{
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/../../build/debug
    } else {
        DESTDIR = $$PWD/../../build/release
    }
}

HEADERS += \
    tinystr.h \
    tinyxml.h

SOURCES += \
    tinystr.cpp \
    tinyxml.cpp \
    tinyxmlerror.cpp \
    tinyxmlparser.cpp
