#ifndef __BOARD_GUI_H
#define __BOARD_GUI_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
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
    int firstIndex, secondIndex;
    ChessSquare * squares[8][8];
public:
    ChessBoard(QWidget *parent=0);
    void loadBoard(bitboard* bb);
    void buttonPressed(int idx);
    void updateButtonStates();
};


} // end of chessGUI namespace

#endif
