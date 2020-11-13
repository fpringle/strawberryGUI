#include "boardGUI.h"
#include "infoGUI.h"
#include <QApplication>


using namespace chessGUI;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ChessBoard window;

    bitboard pb[] = {
        34628232960ULL,
        129ULL,
        68719738880ULL,
        6144ULL,
        2097152ULL,
        16ULL,
        12754334924144640ULL,
        9295429630892703744ULL,
        37383395344384ULL,
        18015498021109760ULL,
        4503599627370496ULL,
        1152921504606846976ULL
    };

    window.loadBoard(pb);

    window.move(300,300);
    window.setWindowTitle("Chess");
    window.show();

    return app.exec();
}
