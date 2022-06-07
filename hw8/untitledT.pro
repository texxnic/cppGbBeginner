include(gtest_dependency.pri)

CONFIG += c++17
CONFIG -= app_bundle
QMAKE_CXXFLAGS += -std=c++17

CONFIG += thread
CONFIG -= qt

HEADERS += \
        person.h \
        phonebook.h \
        phonenumber.h \
        tst_first.h

SOURCES += \
        main.cpp \
        person.cpp \
        phonebook.cpp \
        phonenumber.cpp
