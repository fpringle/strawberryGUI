#ifndef __CHESS_THREAD_H
#define __CHESS_THREAD_H

#include "play.h"

#include <QThread>



Q_DECLARE_METATYPE(chessCore::move_t)


namespace chessGUI {

class WorkerThread : public QThread {
    Q_OBJECT
    void run() override;

signals:
    void resultReady(chessCore::move_t move);

private:
    chessCore::Player *player;

public:
    WorkerThread(chessCore::Player *plyr, QObject *parent=0);

};




} // end of chessGUI namespace

#endif
