#ifndef __PROMOTION_H
#define __PROMOTION_H


#include "board.h"
#include "move.h"

#include <QDialog>
#include <QWidget>
#include <QPushButton>


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
    PromotionDialog(chessCore::colour side, QWidget *parent=0);

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



} // end of chessGUI namespace


#endif
