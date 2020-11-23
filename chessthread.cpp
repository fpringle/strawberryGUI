#include "chessthread.h"



namespace chessGUI {


void WorkerThread::run() {
    chessCore::move_t move = player->iterative_deepening();
    emit resultReady(move);
}

WorkerThread::WorkerThread(chessCore::Player *plyr, QObject *parent)
        : QThread(parent) {
    player = plyr;
}



} // end of chessGUI namespace
