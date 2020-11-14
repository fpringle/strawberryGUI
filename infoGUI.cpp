#include "infoGUI.h"
#include "boardGUI.h"

#include <QLabel>
#include <QScrollArea>
#include <iostream>

namespace chessGUI {


infoPane::infoPane(QWidget *parent) : QWidget(parent) {

    setFixedSize(200,400);
    grid = new QGridLayout(this);

    moveHistory = new QLabel(this);
//    moveHistory->setFixedSize(100,200);
    moveHistory->setAlignment(Qt::AlignTop);
//    moveHistory->setText("1. e2e4    e7e5\n2. g1f3");
//    moveHistory->setStyleSheet("border: 1px solid black");

    QScrollArea *historyScroll = new QScrollArea(this);
    historyScroll->setWidget(moveHistory);

    grid->addWidget(historyScroll, 0, 0);

    castlingRightsLayout = new QGridLayout;
    grid->addLayout(castlingRightsLayout, 1, 0);
    castlingRightsLayout->setSpacing(0);

    for (int i=0; i<4; i++) {
        castlingRightsLabels[i] = new QPushButton(this);
        castlingRightsLabels[i]->setFixedSize(40,40);
        castlingRightsLabels[i]->setIconSize(QSize(40,40));
        castlingRightsLabels[i]->setDisabled(true);
//        castlingRightsLabels[i]->setIcon(pieceIcons[(int(i / 2) * 6) + 4 + (i%2)]);
//        castlingRightsLabels[i]->setStyleSheet("");
        castlingRightsLayout->addWidget(castlingRightsLabels[i], 0, i);
    }

    miscInfo = new QLabel(this);
    miscInfo->setAlignment(Qt::AlignTop);

    grid->addWidget(miscInfo, 2, 0);

    setLayout(grid);
}

void infoPane::setCastlingRights(bool *rights) {
    // white king
    if (rights[0]) {
        castlingRightsLabels[0]->setIcon(pieceIcons[5]);
    }
    else {
        castlingRightsLabels[0]->setIcon(pieceIcons[12]);
    }

    // white queen
    if (rights[1]) {
        castlingRightsLabels[1]->setIcon(pieceIcons[4]);
    }
    else {
        castlingRightsLabels[1]->setIcon(pieceIcons[12]);
    }

    // black king
    if (rights[2]) {
        castlingRightsLabels[2]->setIcon(pieceIcons[11]);
    }
    else {
        castlingRightsLabels[2]->setIcon(pieceIcons[12]);
    }

    // black queen
    if (rights[3]) {
        castlingRightsLabels[3]->setIcon(pieceIcons[10]);
    }
    else {
        castlingRightsLabels[3]->setIcon(pieceIcons[12]);
    }

}

} // end of chessGUI namespace
