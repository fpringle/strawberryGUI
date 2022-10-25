/*
Copyright (c) 2022, Frederick Pringle
All rights reserved.

This source code is licensed under the BSD-style license found in the
LICENSE file in the root directory of this source tree.
*/
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
