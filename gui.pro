######################################################################
# Automatically generated by qmake (3.1) Fri Nov 13 14:23:35 2020
######################################################################

TEMPLATE = app
TARGET = build/strawberryGUI
INCLUDEPATH += $$_PRO_FILE_PWD_/../core
OBJECTS_DIR = obj
MOC_DIR = obj

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += boardGUI.h \
           chessthread.h \
           chooseColour.h \
           infoGUI.h \
           initGUI.h \
           playerGUI.h \
           promotion.h \
           ../core/action.h \
           ../core/board.h \
           ../core/eval.h \
           ../core/hash.h \
           ../core/init.h \
           ../core/move.h \
           ../core/play.h \
           ../core/search.h \
           ../core/tree.h \
           ../core/twiddle.h \
           ../core/typedefs.h \
           boardGUI.h \
           infoGUI.h \
           playerGUI.h
SOURCES += main.cpp \
           boardGUI.cpp \
           chessthread.cpp \
           chooseColour.cpp \
           infoGUI.cpp \
           initGUI.cpp \
           playerGUI.cpp \
           promotion.cpp \
           ../core/action.cpp \
           ../core/board.cpp \
           ../core/check.cpp \
           ../core/eval.cpp \
           ../core/hash.cpp \
           ../core/init.cpp \
           ../core/move.cpp \
           ../core/play.cpp \
           ../core/search.cpp \
           ../core/twiddle.cpp

QT += widgets

RESOURCES = icons.qrc
