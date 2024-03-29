/*
Copyright (c) 2022, Frederick Pringle
All rights reserved.

This source code is licensed under the BSD-style license found in the
LICENSE file in the root directory of this source tree.
*/
#include "boardGUI.h"

#include "colourDialog.h"

#include <QDialog>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

namespace chessGUI {

ColourDialog::ColourDialog(QWidget *parent)
        : QDialog(parent) {
    setWindowTitle("Choose a colour");
    resize(200, 100);

    chosenSide = chessCore::white;

    QGridLayout * grid = new QGridLayout(this);

    int i;
    for (i=0; i < 2; i++) {
        buttons[i] = new QPushButton(this);
        buttons[i]->setIcon(pieceIcons[i * 6]);
        buttons[i]->setFixedSize(100, 100);
        buttons[i]->setIconSize(QSize(100, 100));
        QString buttonColour = (i ? "ivory" : "grey");
        buttons[i]->setStyleSheet("QPushButton { background-color: "
                                  + buttonColour + " }");
        grid->addWidget(buttons[i], 0, i);
    }

    connect(buttons[0], &QPushButton::pressed,
            this, &ColourDialog::chooseWhite);
    connect(buttons[1], &QPushButton::pressed,
            this, &ColourDialog::chooseBlack);

    setLayout(grid);
    setModal(true);

    setWindowIcon(pieceIcons[0]);
}

void ColourDialog::chooseWhite() {
    chosenSide = chessCore::white;
    done(1);
}

void ColourDialog::chooseBlack() {
    chosenSide = chessCore::black;
    done(1);
}

chessCore::colour ColourDialog::choose() {
    QDialog::exec();
    return chosenSide;
}


}   // namespace chessGUI
