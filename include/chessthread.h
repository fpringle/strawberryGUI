/*
Copyright (c) 2022, Frederick Pringle
All rights reserved.

This source code is licensed under the BSD-style license found in the
LICENSE file in the root directory of this source tree.
*/
#ifndef SRC_GUI_CHESSTHREAD_H_
#define SRC_GUI_CHESSTHREAD_H_

#include <QThread>

#include "play.h"



Q_DECLARE_METATYPE(chessCore::move_t)


namespace chessGUI {


/**
 *  \class WorkerThread
 *  \brief Worker thread for computer search.
 *
 *  A threading mechanism for the computer to search for its
 *  next move.
 */
class WorkerThread : public QThread {
    Q_OBJECT
    /** The main loop of the thread. */
    void run() override;

 signals:
    /**
     *  A signal indicating that the computer has chosen its move.
     *
     *  \param move             The computer move.
     */
    void resultReady(quint16 move);

 private:
    /** A reference to the underlying \ref chessCore::Player object. */
    chessCore::Player *player;

 public:
    /**
     *  \brief Constructor for WorkerThread.
     *
     *  \param plyr             A reference to the relevant
     *                          \ref chessCore::Player object.
     *  \param parent           A reference to the parent QObject object.
     */
    explicit WorkerThread(chessCore::Player *plyr, QObject *parent = 0);
};

}   // namespace chessGUI

#endif  // SRC_GUI_CHESSTHREAD_H_
