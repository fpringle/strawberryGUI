#include "playerGUI.h"

#include "board.h"

#include <QGridLayout>

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

    std::cout << "Available moves:\n";
    chessCore::move_t moves[256];
    int num_moves = player->gen_legal_moves(moves);
    for (int i=0; i<num_moves; i++) {
        std::cout << "  " << moves[i].from_sq()
                  << " -> " << moves[i].to_sq() << "\n";
    }
}

} // end of chessGUI namespace
