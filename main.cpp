/* Copyright 2020 Freddy Pringle */
#include <QApplication>

#include <QGridLayout>
#include <string>

#include "boardGUI.h"
#include "infoGUI.h"
#include "init.h"
#include "initGUI.h"
#include "playerGUI.h"



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    chessGUI::init_all();

    std::string s = "1k1r4/pp1b1R2/3q2pp/4p3/2B5/4Q3/PPP2B2/2K5 b - -";
    chessGUI::PlayerGUI *player = new chessGUI::PlayerGUI(chessCore::white, s);

    player->connect(&app, &QApplication::aboutToQuit,
                    player, &chessGUI::PlayerGUI::onClose);
    player->show();
    player->play();
    return app.exec();
}
