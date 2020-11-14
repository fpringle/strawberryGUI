#include "playerGUI.h"

#include "board.h"

#include <QGridLayout>

#include <vector>
#include <sstream>


namespace chessGUI {


PlayerGUI::PlayerGUI(QWidget *parent) : QWidget(parent) {
    player = new chessCore::Player();
    initGraphics();
    updateBoard();
}

PlayerGUI::PlayerGUI(chessCore::bitboard * startPositions, bool * castling,
        bool ep, int dpp, uint8_t clock, uint8_t full_clock, chessCore::colour side,
        chessCore::value_t open_val, chessCore::value_t end_val,
        uint64_t hash, QWidget *parent) : QWidget(parent)  {

    player = new chessCore::Player(startPositions, castling, ep, dpp,
                                   clock, full_clock, side, open_val,
                                   end_val, hash);
    initGraphics();
    updateBoard();
}

PlayerGUI::PlayerGUI(std::string fen, QWidget *parent)
    : QWidget(parent) {
    player = new chessCore::Player(fen);
    initGraphics();
    updateBoard();
}


void PlayerGUI::initGraphics() {
    mainGrid = new QGridLayout(this);
    board = new ChessBoard(this);
    info = new infoPane(this);
    mainGrid->addWidget(board, 0, 0);
    mainGrid->addWidget(info, 0, 1);
    setLayout(mainGrid);
}

void PlayerGUI::updateBoard() {
    chessCore::bitboard pb[12];
    player->getBitboards(pb);
    board->loadBoard(pb);

    bool castling[4];
    player->getCastlingRights(castling);
    info->setCastlingRights(castling);

    updateHistory();
    chessCore::colour side;
    player->getSide(&side);
    if (side == chessCore::white) info->setMiscText("White to move");
    else info->setMiscText("Black to move");
}

void PlayerGUI::interpretMove(int fromIndex, int toIndex) {
    chessCore::move_t moves[256];
    int num_moves = player->gen_legal_moves(moves);
    for (int i=0; i<num_moves; i++) {
        if (moves[i].from_sq() == fromIndex &&
                moves[i].to_sq() == toIndex) {
            doMove(moves[i]);
            return;
        }
    }
    std::cout << "Invalid move\n";
}


void PlayerGUI::doMove(chessCore::move_t move) {
    player->doMoveInPlace(move);
    updateBoard();
    return;

    std::cout << "Available moves:\n";
    chessCore::move_t moves[256];
    int num_moves = player->gen_legal_moves(moves);
    for (int i=0; i<num_moves; i++) {
        std::cout << "  " << moves[i].from_sq()
                  << " -> " << moves[i].to_sq() << "\n";
    }
}

void PlayerGUI::updateHistory() {
    std::stringstream ss;
    player->print_history(ss);
//    std::cout << ss.str();
    info->updateHistory(ss.str());
}


} // end of chessGUI namespace
