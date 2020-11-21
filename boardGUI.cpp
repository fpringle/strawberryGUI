#include "boardGUI.h"
#include "playerGUI.h"
#include <QGridLayout>
//#include <QtSvg>


namespace chessGUI {


QIcon pieceIcons[13] = {
    QIcon(),
    QIcon(),
    QIcon(),
    QIcon(),
    QIcon(),
    QIcon(),

    QIcon(),
    QIcon(),
    QIcon(),
    QIcon(),
    QIcon(),
    QIcon(),
    QIcon()
};


ChessSquare::ChessSquare(int idx, ChessBoard *parent)
    : QPushButton(parent) {
    index = idx;
    if (((idx / 8) % 2) ^ ((idx % 8) % 2)) {
        setStyleSheet("QPushButton { background-color: ivory }");
    }
    else {
        setStyleSheet("QPushButton { background-color: grey }");
    }
}

void ChessSquare::onPress() {
    ChessBoard * prnt = (ChessBoard*)(parentWidget());
    prnt->buttonPressed(index);
}


ChessBoard::ChessBoard(chessCore::colour side, QWidget *parent) : QWidget(parent) {
    setFixedSize(400,400);

    downSide = side;

    QGridLayout *grid = new QGridLayout(this);
    grid->setSpacing(0);

    firstIndex = -1;
    secondIndex = -1;

    int idx;
    int i,j;
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            idx = (7-i)*8+j;
            if (side == chessCore::black) idx = 63 - idx;
            squares[i][j] = new ChessSquare(idx, this);
            squares[i][j]->setFixedSize(50,50);
            squares[i][j]->setIconSize(QSize(50,50));
            connect(squares[i][j], &QPushButton::clicked, squares[i][j], &ChessSquare::onPress);
            grid->addWidget(squares[i][j], i, j);
        }
    }

    setLayout(grid);
}

void ChessBoard::updateButtonStates() {
    int i,j;
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            if (((downSide == chessCore::white) && (firstIndex == 8 * (7 - i) + j))
             || ((downSide == chessCore::black) && (firstIndex == 8 * i + (7 - j)))) {
                squares[i][j]->setDown(true);
            }
            else if (((downSide == chessCore::white) && (secondIndex == 8 * (7 - i) + j))
             || ((downSide == chessCore::black) && (secondIndex == 8 * i + (7 - j)))) {
                squares[i][j]->setDown(true);
            }
            else {
                squares[i][j]->setDown(false);
            }
        }
    }
}

void ChessBoard::buttonPressed(int idx) {
    if (! active) return;

    if (firstIndex == -1) {
        firstIndex = idx;
        secondIndex = -1;
    }
    else if (secondIndex == -1) {
        secondIndex = idx;
        if (firstIndex != secondIndex) {
            PlayerGUI * prnt = (PlayerGUI*)(parentWidget());
            prnt->interpretMove(firstIndex, secondIndex);
        }
        firstIndex = -1;
        secondIndex = -1;
    }
    updateButtonStates();
}

void ChessBoard::loadBoard(chessCore::bitboard* bb) {
    chessCore::bitboard all_pieces = 0ULL;
    chessCore::bitboard tmp;
    int i,j;
    int rank, file;
    for (i=0; i<12; i++) {
        tmp = bb[i];
        for (j=0; tmp && j<64; j++) {
            if (tmp & 1ULL) {
                file = j % 8;
                rank = j / 8;
                if (downSide == chessCore::white) {
                    squares[7 - rank][file]->setIcon(pieceIcons[i]);
                }
                else {
                    squares[rank][7 - file]->setIcon(pieceIcons[i]);
                }
                all_pieces |= (1ULL << j);
            }
            tmp >>= 1;
        }
    }

    for (j=0; j<64; j++) {
        if ((~ all_pieces) & 1ULL) {
            file = j % 8;
            rank = j / 8;
            if (downSide == chessCore::white) {
                squares[7 - rank][file]->setIcon(pieceIcons[12]);
            }
            else {
                squares[rank][7 - file]->setIcon(pieceIcons[12]);
            }
        }
        all_pieces >>= 1;
    }
}

void ChessBoard::setActive(bool act) {
    active = act;
}


} // end of chessGUI namespace
