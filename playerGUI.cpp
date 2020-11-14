#include "playerGUI.h"
#include "chessthread.h"

#include "board.h"

#include <QGridLayout>
#include <QThread>
#include <QCoreApplication>

#include <vector>
#include <sstream>


namespace chessGUI {


PlayerGUI::PlayerGUI(QWidget *parent) : QWidget(parent) {
    player = new chessCore::Player();
    qRegisterMetaType<chessCore::move_t>();
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
    qRegisterMetaType<chessCore::move_t>();
    initGraphics();
    updateBoard();
}

PlayerGUI::PlayerGUI(std::string fen, QWidget *parent)
    : QWidget(parent) {
    player = new chessCore::Player(fen);
    qRegisterMetaType<chessCore::move_t>();
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
    setWindowTitle("Chess");
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
    if (side == chessCore::white) {
        info->setMiscText("White to move");
        board->setActive(true);
    }
    else {
        info->setMiscText("Black to move");
        board->setActive(false);
    }
}

void PlayerGUI::interpretMove(int fromIndex, int toIndex) {
    chessCore::move_t moves[256];
    int num_moves = player->gen_legal_moves(moves);
    for (int i=0; i<num_moves; i++) {
        if (moves[i].from_sq() == fromIndex &&
                moves[i].to_sq() == toIndex) {
            if (doMove(moves[i]) ) {
                compMove();
            }
            return;
        }
    }
    info->setMiscText("Invalid move");
}


bool PlayerGUI::doMove(chessCore::move_t move) {
    player->doMoveInPlace(move);
    updateBoard();
    if (player->gameover()) {
        switch (player->is_checkmate()) {
            case 1:
                info->setMiscText("Black wins!");
                break;
            case -1:
                info->setMiscText("White wins!");
                break;
            case 0:
                info->setMiscText("Draw!");
                break;
        }
        board->setActive(false);
        return false;
    }
    return true;
}

void PlayerGUI::updateHistory() {
    std::stringstream ss;
    player->print_history(ss);
    info->updateHistory(ss.str());
}

void PlayerGUI::compMove() {
    board->setActive(false);
    info->setMiscText("Computer thinking...");

    WorkerThread *workerThread = new WorkerThread(player, this);
    connect(workerThread, &WorkerThread::resultReady,
            this, &PlayerGUI::doMove);
    connect(workerThread, &WorkerThread::finished,
            workerThread, &QObject::deleteLater);
    workerThread->start();
}


} // end of chessGUI namespace
