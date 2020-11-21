#ifndef __PLAYER_GUI_H
#define __PLAYER_GUI_H

#include "boardGUI.h"
#include "infoGUI.h"

#include "play.h"

#include <QWidget>
#include <QGridLayout>
#include <string>

namespace chessGUI {

class PlayerGUI : public QWidget {
private:
    chessCore::Player *player;
    QGridLayout *mainGrid;
    ChessBoard *board;
    InfoPane *info;
    chessCore::colour downSide;
public:
    PlayerGUI(QWidget* parent=0);
    PlayerGUI(chessCore::colour side, QWidget* parent=0);
    PlayerGUI(chessCore::colour side, chessCore::bitboard*,
              bool*, bool, int, uint8_t, uint8_t,
              chessCore::colour, chessCore::value_t, chessCore::value_t,
              uint64_t, QWidget *parent=0);
    PlayerGUI(chessCore::colour side, std::string, QWidget *parent=0);
    void initGraphics();
    void updateBoard();
    bool doMove(chessCore::move_t move);
    void interpretMove(int fromIndex, int toIndex);
    void updateHistory();
    void compMove();
    chessCore::move_t whichPromotion(chessCore::move_t prom);
    void play();
};


} // end of chessGUI namespace

#endif
