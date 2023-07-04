QT -= gui
QT += network
QT += core
QT += sql

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        cfactoryprotocol.cpp \
        cprotocol.cpp \
        database.cpp \
        iprotocol.cpp \
        main.cpp \
        protocoladaugaoptiune.cpp \
        protocoladaugasesiune.cpp \
        protocolamuitatparola.cpp \
        protocolcautaresesiune.cpp \
        protocolgenereazaoptiuni.cpp \
        protocolgenereazarezultat.cpp \
        protocolincreasevote.cpp \
        protocollist.cpp \
        protocolloadsesiuniactive.cpp \
        protocolloadsesiuniinactive.cpp \
        protocollogin.cpp \
        protocolregister.cpp \
        protocolsetsesiuneactiv.cpp \
        protocolsetsesiuneinactiv.cpp \
        server.cpp \
        thread.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    cfactoryprotocol.h \
    cprotocol.h \
    database.h \
    iprotocol.h \
    protocoladaugaoptiune.h \
    protocoladaugasesiune.h \
    protocolamuitatparola.h \
    protocolcautaresesiune.h \
    protocolgenereazaoptiuni.h \
    protocolgenereazarezultat.h \
    protocolincreasevote.h \
    protocollist.h \
    protocolloadsesiuniactive.h \
    protocolloadsesiuniinactive.h \
    protocollogin.h \
    protocolregister.h \
    protocolsetsesiuneactiv.h \
    protocolsetsesiuneinactiv.h \
    server.h \
    thread.h
