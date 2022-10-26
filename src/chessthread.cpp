/*
Copyright (c) 2022, Frederick Pringle
All rights reserved.

This source code is licensed under the BSD-style license found in the
LICENSE file in the root directory of this source tree.
*/
#include "chessthread.h"


namespace chessGUI {


void WorkerThread::run() {
    chessCore::move_t move = player->search(10);
    emit resultReady((quint16)move);
}

WorkerThread::WorkerThread(chessCore::Player *plyr, QObject *parent)
        : QThread(parent) {
    player = plyr;
}



}   // namespace chessGUI
