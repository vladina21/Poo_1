QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    contact.cpp \
    events.cpp \
    expozitii_si_evenimente.cpp \
    giorgio.cpp \
    main.cpp \
    mainwindow.cpp \
    meniuadministrator.cpp \
    register.cpp \
    secdialog.cpp

HEADERS += \
    about.h \
    contact.h \
    events.h \
    expozitii_si_evenimente.h \
    giorgio.h \
    mainwindow.h \
    meniuadministrator.h \
    register.h \
    secdialog.h

FORMS += \
    about.ui \
    contact.ui \
    events.ui \
    expozitii_si_evenimente.ui \
    giorgio.ui \
    mainwindow.ui \
    meniuadministrator.ui \
    register.ui \
    secdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resurse.qrc

DISTFILES += \
    giorgio2.jpg
