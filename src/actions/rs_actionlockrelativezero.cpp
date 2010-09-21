/****************************************************************************
**
** This file is part of the CADuntu project, a 2D CAD program
**
** Copyright (C) 2010 R. van Twisk (caduntu@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
**
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by 
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** This copyright notice MUST APPEAR in all copies of the script!  
**
**********************************************************************/

#include "rs_actionlockrelativezero.h"

#include "rs_snapper.h"
#include "rs_point.h"



RS_ActionLockRelativeZero::RS_ActionLockRelativeZero(
    RS_EntityContainer& container,
    RS_GraphicView& graphicView,
    bool on)
        :RS_ActionInterface("(Un-)lock the relative Zero",
                    container, graphicView) {

    this->on = on;
}


QAction* RS_ActionLockRelativeZero::createGUIAction(RS2::ActionType /*type*/, QObject* /*parent*/) {
	// tr("(Un-)Lock Relative Zero"
    QAction* action = new QAction(tr("(Un-)&Lock Relative Zero"),  NULL);
    action->setStatusTip(tr("(Un-)Lock relative Zero"));
	action->setIcon(QIcon(":/extui/relzerolock.png"));
	action->setCheckable(true);
    return action;
}

void RS_ActionLockRelativeZero::init(int status) {
    RS_ActionInterface::init(status);
    trigger();
    finish();
}

void RS_ActionLockRelativeZero::trigger() {
    graphicView->lockRelativeZero(on);
}

// EOF