/* Copyright 2020 Freddy Pringle */
#ifndef SRC_GUI_COLOURDIALOG_H_
#define SRC_GUI_COLOURDIALOG_H_

#include <QDialog>
#include <QWidget>
#include <QPushButton>

#include "board.h"
#include "move.h"


namespace chessGUI {


/**
 *  \class ColourDialog
 *  \brief A pop-up dialog to prompt the user to choose a colour to play as.
 */
class ColourDialog : public QDialog {
 private:
    /** An array of buttons corresponding to the colour options. */
    QPushButton * buttons[2];

    /** The colour chosen by the user. */
    chessCore::colour chosenSide;

 public:
    /**
     *  \brief The default constructor for ColourDialog.
     *
     *  \param parent           A reference to the parent QWidget object.
     */
    explicit ColourDialog(QWidget *parent = 0);

    /** A callback function for when the user chooses white. */
    void chooseWhite();
    /** A callback function for when the user chooses black. */
    void chooseBlack();

    /**
     *  Execute the main loop and return the chosen colour.
     *
     *  \return                 The chosen colour.
     */
    chessCore::colour choose();
};



}   // namespace chessGUI


#endif  // SRC_GUI_COLOURDIALOG_H_
