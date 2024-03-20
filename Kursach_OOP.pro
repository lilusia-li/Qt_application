QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database.cpp \
    databasepresent.cpp \
    main.cpp \
    mainwindow.cpp \
    ticket.cpp \
    ticket_add_form.cpp \
    ticket_del_form.cpp \
    tickets.cpp \
    tour.cpp \
    tour_add_form.cpp \
    tour_del_form.cpp \
    tourist.cpp \
    tourist_add_form.cpp \
    tourist_del_form.cpp \
    tourists.cpp \
    tours.cpp

HEADERS += \
    database.h \
    databasepresent.h \
    mainwindow.h \
    ticket.h \
    ticket_add_form.h \
    ticket_del_form.h \
    tickets.h \
    tour.h \
    tour_add_form.h \
    tour_del_form.h \
    tourist.h \
    tourist_add_form.h \
    tourist_del_form.h \
    tourists.h \
    tours.h

FORMS += \
    mainwindow.ui \
    ticket_add_form.ui \
    ticket_del_form.ui \
    tickets.ui \
    tour_add_form.ui \
    tour_del_form.ui \
    tourist_add_form.ui \
    tourist_del_form.ui \
    tourists.ui \
    tours.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
