#include "playerGUI.h"

#include <time.h>

#include <fstream>
#include <vector>
#include <sstream>

#include <QGridLayout>
#include <QThread>
#include <QCoreApplication>

#include "chessthread.h"
#include "promotionDialog.h"
#include "colourDialog.h"
#include "board.h"



namespace chessGUI {


PlayerGUI::PlayerGUI(QWidget* parent) : QWidget(parent) {
    ColourDialog* choose = new ColourDialog(this);
//    qRegisterMetaType<chessCore::colour>();
    downSide = choose->choose();
    player = new chessCore::Player(downSide);
    player->read_config("config.toml");
    qRegisterMetaType<chessCore::move_t>();
    initGraphics();
    updateBoard();
}

PlayerGUI::PlayerGUI(chessCore::colour side, QWidget *parent) : QWidget(parent) {
    downSide = side;
    player = new chessCore::Player(downSide);
    qRegisterMetaType<chessCore::move_t>();
    initGraphics();
    updateBoard();
}

PlayerGUI::PlayerGUI(chessCore::colour side, std::string fen, QWidget *parent)
        : QWidget(parent) {
    downSide = side;
    player = new chessCore::Player(fen);
    qRegisterMetaType<chessCore::move_t>();
    initGraphics();
    updateBoard();
}

void PlayerGUI::onClose() {
    time_t t = time(0);
    struct tm * now = localtime(&t);
    std::string logfilename(80, '\0');
    strftime(&logfilename[0], logfilename.size(), "%Y%m%d_%H%M%S.log", now);
    std::ofstream logfile;
    logfile.open(logfilename, std::ios::out | std::ios::trunc);

    if (downSide == chessCore::white) {
        logfile << "User colour: white\n"
                << "Computer colour: black\n";
    }
    else {
        logfile << "User colour: black\n"
                << "Computer colour: white\n";
    }
    logfile << "Computer search timeout: " << player->getTimeout()
            << " seconds\n";


    logfile << "\nMove history:\n";
    player->print_history(logfile);

    logfile.close();
}

void PlayerGUI::initGraphics() {
    QGridLayout* mainGrid = new QGridLayout(this);
    board = new ChessBoard(downSide, this);
    info = new InfoPane(this);
    mainGrid->addWidget(board, 0, 0);
    mainGrid->addWidget(info, 0, 1);
    setLayout(mainGrid);
    setWindowTitle("Chess");
    setWindowIcon(pieceIcons[downSide * 6]);
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
//        board->setActive(true);
    }
    else {
        info->setMiscText("Black to move");
//        board->setActive(false);
    }
    board->setActive(side == downSide);
}

void PlayerGUI::interpretMove(int fromIndex, int toIndex) {
    chessCore::move_t moves[256];
    int num_moves = player->gen_legal_moves(moves);
    chessCore::move_t move;
    for (int i=0; i<num_moves; i++) {
        if (moves[i].from_sq() == fromIndex &&
                moves[i].to_sq() == toIndex) {

            if (moves[i].is_promotion()) {
                move = whichPromotion(moves[i]);
            }
            else {
                move = moves[i];
            }

            if (doMove(move) ) {
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

        if (player->is_checkmate()) {
            chessCore::colour side;
            player->getSide(&side);
            if (side == chessCore::black) {
                info->setMiscText("White wins!");
            }
            else {
                info->setMiscText("Black wins!");
            }
        }
        else {
            info->setMiscText("Draw!");
        }

        board->setActive(false);
        return false;
    }
    return true;
}

void PlayerGUI::updateHistory() {
    std::stringstream ss;
    player->print_history_san(ss);
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

chessCore::move_t PlayerGUI::whichPromotion(chessCore::move_t prom) {
    PromotionDialog *dlg = new PromotionDialog(downSide, this);
    chessCore::piece pc = dlg->choose();
    prom.set_promotion(pc);
    return prom;
}

void PlayerGUI::play() {
    chessCore::colour side_to_move;
    player->getSide(&side_to_move);
    if (downSide != side_to_move) compMove();
}

} // end of chessGUI namespace
