/*
Copyright (c) 2022, Frederick Pringle
All rights reserved.

This source code is licensed under the BSD-style license found in the
LICENSE file in the root directory of this source tree.
*/
#ifndef SRC_GUI_PROMOTIONDIALOG_H_
#define SRC_GUI_PROMOTIONDIALOG_H_


#include <QDialog>
#include <QWidget>
#include <QPushButton>

#include "board.h"
#include "move.h"


namespace chessGUI {


/**
 *  \class PromotionDialog
 *  \brief A pop-up dialog to prompt the user for a
 *         promotion piece selection.
 */
class PromotionDialog : public QDialog {
 private:
    /** An array of buttons corresponding to the piece options. */
    QPushButton * buttons[4];

    /** The piece chosen by the user. */
    chessCore::piece chosenPiece;

 public:
    /**
     *  \brief The default constructor for PromotionDialog.
     *
     *  \param side             The colour that the user is playing as.
     *  \param parent           A reference to the parent QWidget object.
     */
    explicit PromotionDialog(chessCore::colour side, QWidget *parent = 0);

    /** A callback function for when the user chooses knight. */
    void chooseKnight();
    /** A callback function for when the user chooses bishop. */
    void chooseBishop();
    /** A callback function for when the user chooses rook. */
    void chooseRook();
    /** A callback function for when the user chooses queen. */
    void chooseQueen();

    /**
     *  Execute the main loop and return the chosen piece.
     *
     *  \return                 The chosen promotion piece.
     */
    chessCore::piece choose();
};



}   // namespace chessGUI


#endif  // SRC_GUI_PROMOTIONDIALOG_H_
