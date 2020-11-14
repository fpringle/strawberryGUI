#ifndef __INFO_GUI_H
#define __INFO_GUI_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QTextEdit>

#include <string>

namespace chessGUI {


class infoPane : public QWidget {
private:
    QGridLayout *grid;
    QPushButton *castlingRightsLabels[4];
    QGridLayout *castlingRightsLayout;
    QTextEdit *moveHistory;
    QTextEdit *miscInfo;
public:
    infoPane(QWidget *parent=0);
    void setCastlingRights(bool *rights);
    void updateHistory(std::string s);
    void setMiscText(std::string s);
};



} // end of chessGUI namespace


#endif
