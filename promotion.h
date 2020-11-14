#ifndef __PROMOTION_H
#define __PROMOTION_H


#include "board.h"
#include "move.h"

#include <QDialog>
#include <QWidget>
#include <QPushButton>


namespace chessGUI {



class PromotionDialog : public QDialog {
//    Q_OBJECT
private:
    QPushButton * buttons[4];
    chessCore::piece chosenPiece;
public:
    PromotionDialog(chessCore::colour side, QWidget *parent=0);
    void chooseKnight();
    void chooseBishop();
    void chooseRook();
    void chooseQueen();
    chessCore::piece choose();
};



} // end of chessGUI namespace


#endif
