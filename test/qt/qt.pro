TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    ../../crc16.c \
    ../../lib/scunit-clang/scunit.c

HEADERS += \
    ../../crc16.h \
    ../../lib/scunit-clang/scunit.h

INCLUDEPATH += ../../
INCLUDEPATH += ../../lib/scunit-clang
