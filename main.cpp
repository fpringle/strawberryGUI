#include "boardGUI.h"
#include "infoGUI.h"
#include "playerGUI.h"

#include "init.h"

#include <QApplication>
#include <QGridLayout>

using namespace chessGUI;


int main(int argc, char *argv[]) {
    chessCore::init();
    QApplication app(argc, argv);
//    PlayerGUI *player= new PlayerGUI("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w Kq - 1 0");
    PlayerGUI *player = new PlayerGUI(chessCore::black, "8/7k/8/8/8/8/3p3r/K1Q5 b - - 0 1");
//    PlayerGUI *player = new PlayerGUI(chessCore::black, "3k4/R7/8/8/8/8/K7/7Q b - - 0 1");
    player->show();
    return app.exec();
}
