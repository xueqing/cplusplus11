TARGET = cplusplus11
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

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

# [linking]-pthread vs -lpthread
# [linking]-pthread add two more micros definition: #define __USE_REENTRANT 1 #define _REENTRANT 1
# [linking]-pthread add '-D_REENTRANT' for the first COLLECT_GCC_OPTIONS
# [linking]-pthread add '-pthread' for every COLLECT_GCC_OPTIONS(cc1 compiler->as assembling->linker)
# both of them add '-lpthread' for the last COLLECT_GCC_OPTIONS(linker)

# -lpthread vs nopthread
# -lpthread add '-lpthread' for the last COLLECT_GCC_OPTIONS

# [compiling]-pthread vs [linking]-pthread
# same for micro defination

# -pthreads (listed as a synonym for -pthread on Solaris 2)
# -mthread (for MinGW-specific thread support on i386 and x86-64 Windows)
