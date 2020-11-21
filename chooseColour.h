#ifndef __CHOOSE_COLOUR_H
#define __CHOOSE_COLOUR_H


#include "board.h"
#include "move.h"

#include <QDialog>
#include <QWidget>
#include <QPushButton>


namespace chessGUI {



class ColourDialog : public QDialog {
//    Q_OBJECT
private:
    QPushButton * buttons[4];
    chessCore::colour chosenSide;
public:
    ColourDialog(QWidget *parent=0);
    void chooseWhite();
    void chooseBlack();
    chessCore::colour choose();
};



} // end of chessGUI namespace


#endif
