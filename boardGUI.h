#ifndef __BOARD_GUI_H
#define __BOARD_GUI_H

#include "board.h"

#include <QWidget>
#include <QPushButton>
#include <QIcon>

#include <iostream>
#include <cstdint>


using bitboard = uint64_t;

namespace chessGUI {


extern const QIcon pieceIcons[13];


class ChessSquare : public QPushButton {
private:
    int index;
public:
    ChessSquare(int idx, QWidget *parent=0);
    ChessSquare(int idx, const QIcon &icon, QWidget *parent=0);
    void onPress();
};


class ChessBoard : public QWidget {
private:
    bool active;
    int firstIndex, secondIndex;
    ChessSquare * squares[8][8];
    chessCore::colour downSide;
public:
    ChessBoard(chessCore::colour side, QWidget *parent=0);
    void loadBoard(bitboard* bb);
    void buttonPressed(int idx);
    void updateButtonStates();
    void setActive(bool act);
};


} // end of chessGUI namespace

#endif
