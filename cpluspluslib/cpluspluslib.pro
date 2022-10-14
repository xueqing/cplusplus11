TARGET = cpluspluslib
TEMPLATE = lib
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += \
    $$PWD/../openlib

INCLUDEPATH += \
    $$PWD/../depends/include

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

LIBS += \
    -ltinyxmllib


SOURCES += \
    chronolib.cpp \
    threadlib.cpp \
    functionallib.cpp \
    algorithmlib.cpp \
    threadpool.cpp \
    tinyxmltest.cpp \
    sharedptrtest.cpp \
    referencetest.cpp

HEADERS += \
    chronolib.h \
    threadlib.h \
    functionallib.h \
    algorithmlib.h \
    threadpool.h \
    tinyxmltest.h \
    sharedptrtest.h \
    referencetest.h
