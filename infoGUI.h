/* Copyright 2020 Freddy Pringle */
#ifndef SRC_GUI_INFOGUI_H_
#define SRC_GUI_INFOGUI_H_

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QTextEdit>

#include <string>

namespace chessGUI {

/**
 *  \class InfoPane
 *  \brief Information panel
 *
 *  A GUI panel to display more information about the board, such as
 *  the move history and the castling rights.
 */
class InfoPane : public QWidget {
 private:
    /** An array of labels indicating the castling rights. */
    QPushButton *castlingRightsLabels[4];
    /** A text box to display the move history. */
    QTextEdit *moveHistory;
    /** A text box to display general information. */
    QTextEdit *miscInfo;

 public:
    /**
     *  \brief The default constructor for InfoPane.
     *
     *  \param parent           A reference to the parent QWidget object.
     */
    explicit InfoPane(QWidget *parent = 0);

    /**
     *  Update the \ref castlingRightsLabels.
     *
     *  \param rights           An array of booleans representing the
     *                          castling rights.
     */
    void setCastlingRights(bool *rights);

    /**
     *  Update the \ref moveHistory text box.
     *
     *  \param s                A string containing the move history.
     */
    void updateHistory(std::string s);

    /**
     *  Update the \ref miscInfo text box.
     *
     *  \param s                A string containing the text to display.
     */
    void setMiscText(std::string s);
};



}   // namespace chessGUI


#endif  // SRC_GUI_INFOGUI_H_
