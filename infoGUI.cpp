/* Copyright 2020 Freddy Pringle */
#include "infoGUI.h"

#include <QLabel>
#include <QScrollArea>
#include <QTextStream>
#include <QTextEdit>

#include <iostream>

#include "boardGUI.h"


namespace chessGUI {

InfoPane::InfoPane(QWidget *parent) : QWidget(parent) {
//    setFixedSize(200, 400);
    QGridLayout* grid = new QGridLayout(this);

    moveHistory = new QTextEdit(this);
    moveHistory->setReadOnly(true);
    moveHistory->setAlignment(Qt::AlignTop);

    QScrollArea *historyScroll = new QScrollArea(this);
    historyScroll->setFixedSize(170, 324);
    historyScroll->setWidget(moveHistory);

    grid->addWidget(historyScroll, 0, 0);
    moveHistory->setFixedSize(162, 316);

    QGridLayout* castlingRightsLayout = new QGridLayout;
    grid->addLayout(castlingRightsLayout, 1, 0);
    castlingRightsLayout->setSpacing(0);

    for (int i=0; i < 4; i++) {
        castlingRightsLabels[i] = new QPushButton(this);
        castlingRightsLabels[i]->setFixedSize(40, 40);
        castlingRightsLabels[i]->setIconSize(QSize(40, 40));
        castlingRightsLabels[i]->setDisabled(true);
        castlingRightsLayout->addWidget(castlingRightsLabels[i], 0, i);
    }

    miscInfo = new QTextEdit(this);
    miscInfo->setAlignment(Qt::AlignTop);
    miscInfo->setReadOnly(true);
    miscInfo->setFixedSize(162, 40);

    grid->addWidget(miscInfo, 2, 0);

    setLayout(grid);
}

void InfoPane::setCastlingRights(bool *rights) {
    // white king
    if (rights[0]) {
        castlingRightsLabels[0]->setIcon(pieceIcons[5]);
    } else {
        castlingRightsLabels[0]->setIcon(pieceIcons[12]);
    }

    // white queen
    if (rights[1]) {
        castlingRightsLabels[1]->setIcon(pieceIcons[4]);
    } else {
        castlingRightsLabels[1]->setIcon(pieceIcons[12]);
    }

    // black king
    if (rights[2]) {
        castlingRightsLabels[2]->setIcon(pieceIcons[11]);
    } else {
        castlingRightsLabels[2]->setIcon(pieceIcons[12]);
    }

    // black queen
    if (rights[3]) {
        castlingRightsLabels[3]->setIcon(pieceIcons[10]);
    } else {
        castlingRightsLabels[3]->setIcon(pieceIcons[12]);
    }
}

void InfoPane::updateHistory(std::string s) {
    QString qs = QString::fromStdString(s);
    moveHistory->setPlainText(qs);
}

void InfoPane::setMiscText(std::string s) {
    QString qs = QString::fromStdString(s);
    miscInfo->setPlainText(qs);
}


}   // namespace chessGUI
