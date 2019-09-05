TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    task.cpp \
    fcfsscheduler.cpp \
    roundrobinscheduler.cpp \
    sjfscheduler.cpp \
    srtfscheduler.cpp

HEADERS += \
    task.h \
    fcfsscheduler.h \
    roundrobinscheduler.h \
    sjfscheduler.h \
    srtfscheduler.h
