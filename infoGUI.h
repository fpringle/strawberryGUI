#ifndef __INFO_GUI_H
#define __INFO_GUI_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

namespace chessGUI {


class infoPane : public QWidget {
private:
    QGridLayout *grid;
    QPushButton *castlingRightsLabels[4];
    QGridLayout *castlingRightsLayout;
    QLabel *moveHistory;
    QLabel *miscInfo;
public:
    infoPane(QWidget *parent=0);
    void setCastlingRights(bool *rights);
};



} // end of chessGUI namespace


#endif
