/*
Copyright (c) 2022, Frederick Pringle
All rights reserved.

This source code is licensed under the BSD-style license found in the
LICENSE file in the root directory of this source tree.
*/
#ifndef SRC_GUI_INITGUI_H_
#define SRC_GUI_INITGUI_H_

#include <QApplication>

namespace chessGUI {

/** Initialise global GUI constants. */
void initGUI();

/** Initialise global core and GUI constants. */
void init_all();


}   // namespace chessGUI

#endif  // SRC_GUI_INITGUI_H_
