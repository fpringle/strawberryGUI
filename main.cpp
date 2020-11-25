#include <QApplication>
#include <QGridLayout>

#include "boardGUI.h"
#include "infoGUI.h"
#include "init.h"
#include "initGUI.h"
#include "playerGUI.h"



using namespace chessGUI;


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    init_all();

//    PlayerGUI *player= new PlayerGUI("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w Kq - 1 0");
//    PlayerGUI *player = new PlayerGUI(chessCore::black, "8/7k/8/8/8/8/3p3r/K1Q5 b - - 0 1");
//    PlayerGUI *player = new PlayerGUI(chessCore::white, "8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - - ");
    PlayerGUI *player = new PlayerGUI(chessCore::white, "1k1r4/pp1b1R2/3q2pp/4p3/2B5/4Q3/PPP2B2/2K5 b - -");

    player->connect(&app, &QApplication::aboutToQuit, player, &PlayerGUI::onClose);
    player->show();
    player->play();
    return app.exec();
}
