#ifndef __BOARD_GUI_H
#define __BOARD_GUI_H

#include "board.h"

#include <QWidget>
#include <QPushButton>
#include <QIcon>

#include <iostream>
#include <cstdint>



/**
 *  \namespace chessGUI
 *  \brief The namespace for the GUI of the chess engine.
 *
 *  The namespace chessGUI is written using Qt and provides a
 *  basic graphical interface for the user to play chess against
 *  the computer.
 */
namespace chessGUI {

/**
 *  An array of QIcon objects to graphically represent the chess pieces.
 */
extern QIcon pieceIcons[13];

class ChessBoard;


/**
 *  \class ChessSquare
 *  \brief A push-button representing a single square on the board.
 */
class ChessSquare : public QPushButton {
private:
    /** The index of the chess square. */
    int index;
public:
    /**
     *  \brief Default constrcutor for ChessSquare.
     *
     *  \param idx          The index of the square. See \ref index.
     *  \param parent       A reference to the parent ChessBoard.
     */
    ChessSquare(int idx, ChessBoard *parent=0);

    /**
     *  The callback function when the button is pressed. It calls the
     *  \ref ChessBoard::buttonPressed() method of the parent ChessBoard object.
     */
    void onPress();
};


/**
 *  \class ChessBoard
 *  \brief A graphical representation of the chess board.
 */
class ChessBoard : public QWidget {
private:
    /**
     *  Indicates whether the board is ready for user input.
     *  True when it's the user's turn, false when the computer
     *  is thinking.
     */
    bool active;

    /**
     *  When the user presses the first square of their move, firstIndex
     *  is set to the index of that square.
     */
    int firstIndex;

    /**
     *  When the user presses the second square of their move, secondIndex
     *  is set to the index of that square.
     */
    int secondIndex;

    /**
     *  An array containing pointers to the 64 squares on the board.
     */
    ChessSquare * squares[8][8];

    /**
     *  Indicates the colour that the user is playing as.
     */
    chessCore::colour downSide;

public:
    /**
     *  \brief Default constructor for ChessBoard.
     *
     *  \param side         The colour that the user is playing as.
     *                      See \ref downSide.
     *  \param parent       A reference to the parent QWidget object.
     */
    ChessBoard(chessCore::colour side, QWidget *parent=0);

    /**
     *  Load the positions of the pieces from an array of bitboards.
     *
     *  \param bb           The array of bitboards to load.
     */
    void loadBoard(chessCore::bitboard* bb);

    /**
     *  Called when one of the squares is pressed.
     *
     *  \param idx          The index of the pressed square.
     */
    void buttonPressed(int idx);

    /**
     *  Update the appearance of the chess squares to reflect whether
     *  or not they've been pressed.
     */
    void updateButtonStates();

    /**
     *  Update the \ref active member variable.
     *
     *  \param act          A boolean indicating whether the GUI should
     *                      accept input.
     */
    void setActive(bool act);
};


} // end of chessGUI namespace

#endif
