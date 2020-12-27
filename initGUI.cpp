/* Copyright 2020 Freddy Pringle */
#include "initGUI.h"

#include <QApplication>

#include "boardGUI.h"
#include "init.h"



namespace chessGUI {


void initGUI() {
    pieceIcons[0].addFile(":/icons/wp.svg");
    pieceIcons[1].addFile(":/icons/wr.svg");
    pieceIcons[2].addFile(":/icons/wn.svg");
    pieceIcons[3].addFile(":/icons/wb.svg");
    pieceIcons[4].addFile(":/icons/wq.svg");
    pieceIcons[5].addFile(":/icons/wk.svg");
    pieceIcons[6].addFile(":/icons/bp.svg");
    pieceIcons[7].addFile(":/icons/br.svg");
    pieceIcons[8].addFile(":/icons/bn.svg");
    pieceIcons[9].addFile(":/icons/bb.svg");
    pieceIcons[10].addFile(":/icons/bq.svg");
    pieceIcons[11].addFile(":/icons/bk.svg");
}


void init_all() {
    chessCore::init();
    initGUI();
}


}   // namespace chessGUI
