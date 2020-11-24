#ifndef __PLAYER_GUI_H
#define __PLAYER_GUI_H

#include "boardGUI.h"
#include "infoGUI.h"

#include "play.h"

#include <QWidget>
#include <QGridLayout>
#include <string>

namespace chessGUI {


/**
 *  \class PlayerGUI
 *  \brief The main class of the GUI.
 *
 *  PlayerGUI wraps together all the elements of the GUI in one window
 *  to provide the user with a graphical interface to play against the
 *  computer.
 */
class PlayerGUI : public QWidget {
private:
    /**
     *  A reference to a \ref chessCore::Player object that handles all
     *  the backend operation.
     */
    chessCore::Player *player;

    /** The pane that displays the chess board. */
    ChessBoard *board;

    /** The pane that displays the other information. */
    InfoPane *info;

    /** The colour the user is playing as. */
    chessCore::colour downSide;

public:
    /**
     *  \brief Default constructor for PlayerGUI. Graphically prompt the user
     *  to choose their colour.
     *
     *  \param parent               A reference to the parent QWidget object.
     */
    PlayerGUI(QWidget* parent=0);

    /**
     *  \brief Parameterised constructor for PlayerGUI. Specify the user colour.
     *
     *  \param side                 The colour that the user will play as.
     *  \param parent               A reference to the parent QWidget object.
     */
    PlayerGUI(chessCore::colour side, QWidget* parent=0);

    /**
     *  \brief FEN constructor for PlayerGUI.
     *
     *  Construct the board state using Forsyth-Edwards Notation (FEN).
     *  Specify the user colour.
     *
     *  \param side                 The colour that the user will play as.
     *  \param fen                  A string representing the required board state
     *                              in FEN format.
     *  \param parent               A reference to the parent QWidget object.
     */
    PlayerGUI(chessCore::colour side, std::string fen, QWidget *parent=0);

    /** Cleanup code */
    void onClose();

    /** Initialise the GUI. */
    void initGraphics();

    /** Update the board display and the info pane. */
    void updateBoard();

    /** Update the move history. */
    void updateHistory();

    /**
     *  Play a move on the board.
     *
     *  \param move                 The move to be played.
     *  \return                     False if the game is over, true otherwise.
     */
    bool doMove(chessCore::move_t move);

    /**
     *  Interpret a move played by the user. Called by ChessBoard::buttonPressed.
     *
     *  \param fromIndex            The index of the first button pressed.
     *  \param toIndex              The index of the second button pressed.
     */
    void interpretMove(int fromIndex, int toIndex);

    /** Get the computer's move. */
    void compMove();

    /**
     *  Prompt the user to choose a promotion piece.
     *
     *  \param prom                 The move being played.
     *  \return                     The move with the correction promotion
     *                              piece set.
     */
    chessCore::move_t whichPromotion(chessCore::move_t prom);

    /** Play chess! */
    void play();
};


} // end of chessGUI namespace

#endif
