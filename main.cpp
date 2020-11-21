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
//    PlayerGUI *player = new PlayerGUI(chessCore::white, "3k4/R7/8/8/8/8/K7/7Q b - - 0 1");
    PlayerGUI *player = new PlayerGUI();
    player->show();
    player->play();
    return app.exec();
}
