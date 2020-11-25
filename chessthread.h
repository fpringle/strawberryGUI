#ifndef __CHESS_THREAD_H
#define __CHESS_THREAD_H

#include "play.h"

#include <QThread>



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
    WorkerThread(chessCore::Player *plyr, QObject *parent=0);

};




} // end of chessGUI namespace

#endif
