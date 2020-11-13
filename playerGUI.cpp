#include "playerGUI.h"



namespace chessGUI {


PlayerGUI::PlayerGUI(QWidget *parent)
    : QWidget(parent), chessCore::Player()  {

}

PlayerGUI::PlayerGUI(chessCore::bitboard * startPositions, bool * castling,
        bool ep, int dpp, uint8_t clock, uint8_t full_clock, chessCore::colour side,
        chessCore::value_t open_val, chessCore::value_t end_val,
        uint64_t hash, QWidget *parent)
    : QWidget(parent),
      chessCore::Player(startPositions, castling, ep, dpp,
                        clock, full_clock, side, open_val,
                        end_val, hash)  {

}

PlayerGUI::PlayerGUI(std::string fen, QWidget *parent)
    : QWidget(parent), chessCore::Player(fen)  {

}





} // end of chessGUI namespace
