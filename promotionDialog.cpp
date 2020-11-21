#include "boardGUI.h"
#include "promotionDialog.h"

#include <QDialog>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

namespace chessGUI {

PromotionDialog::PromotionDialog(chessCore::colour side, QWidget *parent)
        : QDialog(parent) {
    setWindowTitle("Choose a piece");
    chosenPiece = chessCore::pawn;

    QGridLayout * grid = new QGridLayout(this);

    int i;
    int icons[4] = {2,3,1,4};
    for (i=0; i<4; i++) {
        buttons[i] = new QPushButton(this);
        if (side == chessCore::white) {
            buttons[i]->setIcon(pieceIcons[icons[i]]);
        }
        else {
            buttons[i]->setIcon(pieceIcons[icons[i] + 6]);
        }
        buttons[i]->setFixedSize(50,50);
        buttons[i]->setIconSize(QSize(50,50));
        grid->addWidget(buttons[i], 0, i);
    }

    connect(buttons[0], &QPushButton::pressed,
            this, &PromotionDialog::chooseKnight);
    connect(buttons[1], &QPushButton::pressed,
            this, &PromotionDialog::chooseBishop);
    connect(buttons[2], &QPushButton::pressed,
            this, &PromotionDialog::chooseRook);
    connect(buttons[3], &QPushButton::pressed,
            this, &PromotionDialog::chooseQueen);

    setLayout(grid);
    setModal(true);
}

void PromotionDialog::chooseKnight() {
    chosenPiece = chessCore::knight;
    done(1);
}

void PromotionDialog::chooseBishop() {
    chosenPiece = chessCore::bishop;
    done(1);
}

void PromotionDialog::chooseRook() {
    chosenPiece = chessCore::rook;
    done(1);
}

void PromotionDialog::chooseQueen() {
    chosenPiece = chessCore::queen;
    done(1);
}

chessCore::piece PromotionDialog::choose() {
    QDialog::exec();
    return chosenPiece;
}


} // end of chessGUI namespace
