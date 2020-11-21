######################################################################
# Automatically generated by qmake (3.1) Fri Nov 13 14:23:35 2020
######################################################################

TEMPLATE = app



win32 {
    TARGET = build/win32/strawberryGUI
    OBJECTS_DIR = obj
    MOC_DIR = obj/windows
    MAKEFILE = Makefile.win32
    CONFIG -= debug_and_release debug_and_release_target
} else:unix {
    TARGET = build/unix/strawberryGUI
    OBJECTS_DIR = obj/unix
    MOC_DIR = obj/unix
    MAKEFILE = Makefile
}

CORE_DIR = $${_PRO_FILE_PWD}../core
INCLUDEPATH += $${CORE_DIR}


# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

win32 {
    QMAKE_CXXFLAGS += -std=gnu++11
}

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QT += widgets

RESOURCES = icons.qrc

ICON = icons/icon.ico

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
           promotion.cpp

win32 {
    LIBS += $${CORE_DIR}/obj/win32/action.o \
            $${CORE_DIR}/obj/win32/board.o \
            $${CORE_DIR}/obj/win32/check.o \
            $${CORE_DIR}/obj/win32/eval.o \
            $${CORE_DIR}/obj/win32/hash.o \
            $${CORE_DIR}/obj/win32/init.o \
            $${CORE_DIR}/obj/win32/move.o \
            $${CORE_DIR}/obj/win32/play.o \
            $${CORE_DIR}/obj/win32/search.o \
            $${CORE_DIR}/obj/win32/twiddle.o


    PRE_TARGETDEPS +=   \
                        $${CORE_DIR}/obj/win32/action.o \
                        $${CORE_DIR}/obj/win32/board.o \
                        $${CORE_DIR}/obj/win32/check.o \
                        $${CORE_DIR}/obj/win32/eval.o \
                        $${CORE_DIR}/obj/win32/hash.o \
                        $${CORE_DIR}/obj/win32/init.o \
                        $${CORE_DIR}/obj/win32/move.o \
                        $${CORE_DIR}/obj/win32/play.o \
                        $${CORE_DIR}/obj/win32/search.o \
                        $${CORE_DIR}/obj/win32/twiddle.o


    make_core_win32_object_dir.target = make_core_win32_object_dir
    make_core_win32_object_dir.commands = "@test -d $${CORE_DIR}/obj/win32 || mkdir -p $${CORE_DIR}/obj/win32"

    actiontarget.target = $${CORE_DIR}/obj/win32/action.o
    actiontarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/win32/action.o $${CORE_DIR}/action.cpp
    actiontarget.depends = make_core_win32_object_dir

    boardtarget.target = $${CORE_DIR}/obj/win32/board.o
    boardtarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/win32/board.o $${CORE_DIR}/board.cpp
    boardtarget.depends = make_core_win32_object_dir

    checktarget.target = $${CORE_DIR}/obj/win32/check.o
    checktarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/win32/check.o $${CORE_DIR}/check.cpp
    checktarget.depends = make_core_win32_object_dir

    evaltarget.target = $${CORE_DIR}/obj/win32/eval.o
    evaltarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/win32/eval.o $${CORE_DIR}/eval.cpp
    evaltarget.depends = make_core_win32_object_dir

    hashtarget.target = $${CORE_DIR}/obj/win32/hash.o
    hashtarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/win32/hash.o $${CORE_DIR}/hash.cpp
    hashtarget.depends = make_core_win32_object_dir

    inittarget.target = $${CORE_DIR}/obj/win32/init.o
    inittarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/win32/init.o $${CORE_DIR}/init.cpp
    inittarget.depends = make_core_win32_object_dir

    movetarget.target = $${CORE_DIR}/obj/win32/move.o
    movetarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/win32/move.o $${CORE_DIR}/move.cpp
    movetarget.depends = make_core_win32_object_dir

    playtarget.target = $${CORE_DIR}/obj/win32/play.o
    playtarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/win32/play.o $${CORE_DIR}/play.cpp
    playtarget.depends = make_core_win32_object_dir

    searchtarget.target = $${CORE_DIR}/obj/win32/search.o
    searchtarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/win32/search.o $${CORE_DIR}/search.cpp
    searchtarget.depends = make_core_win32_object_dir

    twiddletarget.target = $${CORE_DIR}/obj/win32/twiddle.o
    twiddletarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/win32/twiddle.o $${CORE_DIR}/twiddle.cpp
    twiddletarget.depends = make_core_win32_object_dir

    QMAKE_EXTRA_TARGETS += \
                            actiontarget \
                            boardtarget \
                            checktarget \
                            evaltarget \
                            hashtarget \
                            inittarget \
                            movetarget \
                            playtarget \
                            searchtarget \
                            twiddletarget \
                            make_core_win32_object_dir

} else:unix {
    LIBS += $${CORE_DIR}/obj/action.o \
            $${CORE_DIR}/obj/board.o \
            $${CORE_DIR}/obj/check.o \
            $${CORE_DIR}/obj/eval.o \
            $${CORE_DIR}/obj/hash.o \
            $${CORE_DIR}/obj/init.o \
            $${CORE_DIR}/obj/move.o \
            $${CORE_DIR}/obj/play.o \
            $${CORE_DIR}/obj/search.o \
            $${CORE_DIR}/obj/twiddle.o


    PRE_TARGETDEPS +=   \
                        $${CORE_DIR}/obj/action.o \
                        $${CORE_DIR}/obj/board.o \
                        $${CORE_DIR}/obj/check.o \
                        $${CORE_DIR}/obj/eval.o \
                        $${CORE_DIR}/obj/hash.o \
                        $${CORE_DIR}/obj/init.o \
                        $${CORE_DIR}/obj/move.o \
                        $${CORE_DIR}/obj/play.o \
                        $${CORE_DIR}/obj/search.o \
                        $${CORE_DIR}/obj/twiddle.o



    actiontarget.target = $${CORE_DIR}/obj/action.o
    actiontarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/action.o $${CORE_DIR}/action.cpp

    boardtarget.target = $${CORE_DIR}/obj/board.o
    boardtarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/board.o $${CORE_DIR}/board.cpp

    checktarget.target = $${CORE_DIR}/obj/check.o
    checktarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/check.o $${CORE_DIR}/check.cpp

    evaltarget.target = $${CORE_DIR}/obj/eval.o
    evaltarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/eval.o $${CORE_DIR}/eval.cpp

    hashtarget.target = $${CORE_DIR}/obj/hash.o
    hashtarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/hash.o $${CORE_DIR}/hash.cpp

    inittarget.target = $${CORE_DIR}/obj/init.o
    inittarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/init.o $${CORE_DIR}/init.cpp

    movetarget.target = $${CORE_DIR}/obj/move.o
    movetarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/move.o $${CORE_DIR}/move.cpp

    playtarget.target = $${CORE_DIR}/obj/play.o
    playtarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/play.o $${CORE_DIR}/play.cpp

    searchtarget.target = $${CORE_DIR}/obj/search.o
    searchtarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/search.o $${CORE_DIR}/search.cpp

    twiddletarget.target = $${CORE_DIR}/obj/twiddle.o
    twiddletarget.commands = $(CXX) -c $(CXXFLAGS) $(INCPATH) -o $${CORE_DIR}/obj/twiddle.o $${CORE_DIR}/twiddle.cpp

    QMAKE_EXTRA_TARGETS += \
                            actiontarget \
                            boardtarget \
                            checktarget \
                            evaltarget \
                            hashtarget \
                            inittarget \
                            movetarget \
                            playtarget \
                            searchtarget \
                            twiddletarget
}


