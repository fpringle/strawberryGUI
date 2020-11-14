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
    PlayerGUI *player= new PlayerGUI("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w Kq - 1 0");
    player->show();
    return app.exec();
}


int _main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    QGridLayout *grid = new QGridLayout(window);
    ChessBoard brd(window);
    infoPane info(window);
    grid->addWidget(&brd, 0, 0);
    grid->addWidget(&info, 0, 1);
    window->setLayout(grid);

    bitboard pb[12];
    chessCore::board b;
    b.getBitboards(pb);
    brd.loadBoard(pb);

    window->show();
    return app.exec();
}
