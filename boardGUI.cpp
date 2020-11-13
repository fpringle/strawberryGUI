#include "boardGUI.h"

#include <QGridLayout>


namespace chessGUI {


const QIcon pieceIcons[13] = {
    QIcon("icons/wp.svg"),
    QIcon("icons/wr.svg"),
    QIcon("icons/wn.svg"),
    QIcon("icons/wb.svg"),
    QIcon("icons/wq.svg"),
    QIcon("icons/wk.svg"),
    QIcon("icons/bp.svg"),
    QIcon("icons/br.svg"),
    QIcon("icons/bn.svg"),
    QIcon("icons/bb.svg"),
    QIcon("icons/bq.svg"),
    QIcon("icons/bk.svg"),
    QIcon()
};


ChessSquare::ChessSquare(int idx, QWidget *parent)
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


ChessBoard::ChessBoard(QWidget *parent) : QWidget(parent) {
    QGridLayout *grid = new QGridLayout(this);
    grid->setSpacing(0);

    firstIndex = -1;
    secondIndex = -1;

    int idx;
    int i,j;
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            idx = (7-i)*8+j;
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
            if (firstIndex == 8 * (7 - i) + j) {
                squares[i][j]->setDown(true);
            }
            else if (secondIndex == 8 * (7 - i) + j) {
                squares[i][j]->setDown(true);
            }
            else {
                squares[i][j]->setDown(false);
            }
        }
    }
}

void ChessBoard::buttonPressed(int idx) {
    if (firstIndex == -1) {
        firstIndex = idx;
        secondIndex = -1;
    }
    else if (secondIndex == -1) {
        secondIndex = idx;
        std::cout << firstIndex << ", " << secondIndex << std::endl; // do something
        firstIndex = -1;
        secondIndex = -1;
    }
    updateButtonStates();
}

void ChessBoard::loadBoard(bitboard* bb) {
    bitboard all_pieces = 0ULL;
    bitboard tmp;
    int i,j;
    int rank, file;
    for (i=0; i<12; i++) {
        tmp = bb[i];
        for (j=0; tmp && j<64; j++) {
            if (tmp & 1ULL) {
                file = j % 8;
                rank = j / 8;
                squares[7 - rank][file]->setIcon(pieceIcons[i]);
                all_pieces |= (1ULL << j);
            }
            tmp >>= 1;
        }
    }

    for (j=0; j<64; j++) {
        if ((~ all_pieces) & 1ULL) {
            file = j % 8;
            rank = j / 8;
            squares[7 - rank][file]->setIcon(pieceIcons[12]);
        }
        all_pieces >>= 1;
    }
}


} // end of chessGUI namespace
