QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    datecont.cpp \
    iuser.cpp \
    main.cpp \
    mainwindow.cpp \
    meniuprincipal.cpp \
    register.cpp \
    schimbareparola.cpp \
    sesiunevot.cpp \
    sesiunevotare.cpp \
    user.cpp \
    vot.cpp \
    votant.cpp

HEADERS += \
    admin.h \
    datecont.h \
    iuser.h \
    mainwindow.h \
    meniuprincipal.h \
    register.h \
    schimbareparola.h \
    sesiunevot.h \
    sesiunevotare.h \
    user.h \
    vot.h \
    votant.h

FORMS += \
    datecont.ui \
    mainwindow.ui \
    meniuprincipal.ui \
    register.ui \
    schimbareparola.ui \
    sesiunevotare.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resurse.qrc
