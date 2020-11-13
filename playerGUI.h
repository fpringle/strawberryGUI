#ifndef __PLAYER_GUI_H
#define __PLAYER_GUI_H

#include "boardGUI.h"

#include "play.h"

#include <QWidget>
#include <string>

namespace chessGUI {

class PlayerGUI : public QWidget, public chessCore::Player {
public:
    PlayerGUI(QWidget *parent=0);
    PlayerGUI(chessCore::bitboard*, bool*, bool, int, uint8_t, uint8_t,
            chessCore::colour, chessCore::value_t, chessCore::value_t,
            uint64_t, QWidget *parent=0);
    PlayerGUI(std::string, QWidget *parent=0);
};


} // end of chessGUI namespace

#endif
