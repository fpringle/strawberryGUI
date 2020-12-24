#include "chessthread.h"



namespace chessGUI {


void WorkerThread::run() {
    chessCore::move_t move = player->search();
    emit resultReady((quint16)move);
}

WorkerThread::WorkerThread(chessCore::Player *plyr, QObject *parent)
        : QThread(parent) {
    player = plyr;
}



} // end of chessGUI namespace
