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

    chessGUI::PlayerGUI *player = new chessGUI::PlayerGUI(chessCore::white);

    player->connect(&app, &QApplication::aboutToQuit,
                    player, &chessGUI::PlayerGUI::onClose);
    player->show();
    player->play();
    return app.exec();
}
