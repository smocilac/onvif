TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $$PWD/../../gsoap/gsoap/runtime \
                $$PWD/../../onvifgen \
                $$PWD/../../include

SOURCES += main.cpp \
    ptzcontrol.cpp \
    $$PWD/../../gsoap/gsoap/runtime/duration.cpp \
    $$PWD/../../gsoap/gsoap/runtime/mecevp.cpp \
    $$PWD/../../gsoap/gsoap/runtime/smdevp.cpp \
    $$PWD/../../gsoap/gsoap/runtime/stdsoap2.cpp \
    $$PWD/../../gsoap/gsoap/runtime/threads.cpp \
    $$PWD/../../gsoap/gsoap/runtime/wsaapi.cpp \
    $$PWD/../../gsoap/gsoap/runtime/wsseapi.cpp \
    $$PWD/../../include/onvifclientdevice.cpp \
    $$PWD/../../include/onvifclientmedia.cpp \
    $$PWD/../../include/onvifclientptz.cpp \
    $$PWD/../../onvifgen/*.cpp


DEFINES += WITH_OPENSSL WITH_PURE_VIRTUAL


HEADERS += ptzcontrol.h \
    $$PWD/../../gsoap/gsoap/runtime/duration.h \
    $$PWD/../../gsoap/gsoap/runtime/mecevp.h \
    $$PWD/../../gsoap/gsoap/runtime/smdevp.h \
    $$PWD/../../gsoap/gsoap/runtime/stdsoap2.h \
    $$PWD/../../gsoap/gsoap/runtime/threads.h \
    $$PWD/../../gsoap/gsoap/runtime/wsaapi.h \
    $$PWD/../../gsoap/gsoap/runtime/wsseapi.h \
    $$PWD/../../include/onvifclientdevice.h \
    $$PWD/../../include/onvifclientmedia.h \
    $$PWD/../../include/onvifclientptz.h \
    $$PWD/../../onvifgen/*.h


LIBS += -lcrypto -lssl

