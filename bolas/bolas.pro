######################################################################
# Automatically generated by qmake (3.1) Sat Feb 3 20:11:34 2024
######################################################################

TEMPLATE = app
TARGET = bolas
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += bola.h \
           dcontrolbolas.h \
           dposicionbolas.h \
           dtablabolas.h \
           dtablachoques.h \
           mainwindow.h \
           panelposicionbola.h \
           panelposicioneschoques.h \
           wcontrolbola.h \
           wposicionbola.h
FORMS += dcontrolbolas.ui \
         dposicionbolas.ui \
         dtablabolas.ui \
         dtablachoques.ui \
         wcontrolbola.ui \
         wposicionbola.ui
SOURCES += bola.cpp \
           dcontrolbolas.cpp \
           dposicionbolas.cpp \
           dtablabolas.cpp \
           dtablachoques.cpp \
           main.cpp \
           mainwindow.cpp \
           panelposicionbola.cpp \
           panelposicioneschoques.cpp \
           wcontrolbola.cpp \
           wposicionbola.cpp
QT += widgets
