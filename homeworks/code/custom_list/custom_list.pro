TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += \
        main.cpp \
    customlist.cpp

HEADERS += \
    customlist.h
