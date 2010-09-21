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

#include "rs_actiondrawcircle.h"

#include "rs_snapper.h"



RS_ActionDrawCircle::RS_ActionDrawCircle(RS_EntityContainer& container,
        RS_GraphicView& graphicView)
        :RS_PreviewActionInterface("Draw circles",
                           container, graphicView) {
    reset();
}



RS_ActionDrawCircle::~RS_ActionDrawCircle() {}


QAction* RS_ActionDrawCircle::createGUIAction(RS2::ActionType /*type*/, QObject* /*parent*/) {
/*RVT_PORT    QAction* action = new QAction(tr("Circle: Center, Point"),
                                  tr("Center, &Point"),
                                  QKeySequence(), NULL); */
	// "Circle: Center, Point"
    QAction* action = new QAction(tr("Center, &Point"), NULL);
	action->setIcon(QIcon(":/extui/circles.png"));
    action->setStatusTip(tr("Draw circles with center and point"));
    return action;
}

void RS_ActionDrawCircle::reset() {
    data = RS_CircleData(RS_Vector(false), 0.0);
}



void RS_ActionDrawCircle::init(int status) {
    RS_PreviewActionInterface::init(status);

    reset();
}



void RS_ActionDrawCircle::trigger() {
    RS_PreviewActionInterface::trigger();

    RS_Circle* circle = new RS_Circle(container,
                                      data);
    circle->setLayerToActive();
    circle->setPenToActive();
    container->addEntity(circle);

    // upd. undo list:
    if (document!=NULL) {
        document->startUndoCycle();
        document->addUndoable(circle);
        document->endUndoCycle();
    }
	graphicView->redraw(RS2::RedrawDrawing);
    graphicView->moveRelativeZero(circle->getCenter());

    setStatus(SetCenter);
    reset();

    RS_DEBUG->print("RS_ActionDrawCircle::trigger(): circle added: %d",
                    circle->getId());
}



void RS_ActionDrawCircle::mouseMoveEvent(RS_MouseEvent* e) {
    RS_DEBUG->print("RS_ActionDrawCircle::mouseMoveEvent begin");

    RS_Vector mouse = snapPoint(e);
    switch (getStatus()) {
    case SetCenter:
        data.center = mouse;
        break;

    case SetRadius:
        if (data.center.valid) {
            data.radius = data.center.distanceTo(mouse);
            deletePreview();
            preview->addEntity(new RS_Circle(preview,
                                             data));
            drawPreview();
        }
        break;
    }

    RS_DEBUG->print("RS_ActionDrawCircle::mouseMoveEvent end");
}



void RS_ActionDrawCircle::mouseReleaseEvent(RS_MouseEvent* e) {
    if (RS2::qtToRsButtonState(e->button())==RS2::LeftButton) {
        RS_CoordinateEvent ce(snapPoint(e));
        coordinateEvent(&ce);
    } else if (RS2::qtToRsButtonState(e->button())==RS2::RightButton) {
        deletePreview();
        init(getStatus()-1);
    }
}



void RS_ActionDrawCircle::coordinateEvent(RS_CoordinateEvent* e) {
    if (e==NULL) {
        return;
    }

    RS_Vector mouse = e->getCoordinate();

    switch (getStatus()) {
    case SetCenter:
        data.center = mouse;
        graphicView->moveRelativeZero(mouse);
        setStatus(SetRadius);
        break;

    case SetRadius:
        if (data.center.valid) {
            graphicView->moveRelativeZero(mouse);
            data.radius = data.center.distanceTo(mouse);
            trigger();
        }
        //setStatus(SetCenter);
        break;

    default:
        break;
    }
}



void RS_ActionDrawCircle::commandEvent(RS_CommandEvent* e) {
    RS_String c = e->getCommand().lower();

    if (checkCommand("help", c)) {
        if (RS_DIALOGFACTORY!=NULL) {
            RS_DIALOGFACTORY->commandMessage(msgAvailableCommands()
                                             + getAvailableCommands().join(", "));
        }
        return;
    }

    switch (getStatus()) {

    case SetRadius: {
            bool ok;
            double r = RS_Math::eval(c, &ok);
            if (ok==true) {
                data.radius = r;
            } else {
                if (RS_DIALOGFACTORY!=NULL) {
                    RS_DIALOGFACTORY->commandMessage(
                        tr("Not a valid expression"));
                }
            }
            trigger();
            //setStatus(SetCenter);
        }
        break;

    default:
        break;
    }
}



RS_StringList RS_ActionDrawCircle::getAvailableCommands() {
    RS_StringList cmd;
    return cmd;
}


void RS_ActionDrawCircle::updateMouseButtonHints() {
    switch (getStatus()) {
    case SetCenter:
        if (RS_DIALOGFACTORY!=NULL) {
            RS_DIALOGFACTORY->updateMouseWidget(
                tr("Specify center"), tr("Cancel"));
        }
        break;
    case SetRadius:
        if (RS_DIALOGFACTORY!=NULL) {
            RS_DIALOGFACTORY->updateMouseWidget(tr("Specify radius"), tr("Back"));
        }
        break;
    default:
        if (RS_DIALOGFACTORY!=NULL) {
            RS_DIALOGFACTORY->updateMouseWidget("", "");
        }
        break;
    }
}



void RS_ActionDrawCircle::showOptions() {
    RS_ActionInterface::showOptions();
}



void RS_ActionDrawCircle::hideOptions() {
    RS_ActionInterface::hideOptions();
}



void RS_ActionDrawCircle::updateMouseCursor() {
    graphicView->setMouseCursor(RS2::CadCursor);
}



void RS_ActionDrawCircle::updateToolBar() {
    if (!isFinished()) {
        if (RS_DIALOGFACTORY!=NULL) {
            RS_DIALOGFACTORY->requestToolBar(RS2::ToolBarSnap);
        }
    } else {
        if (RS_DIALOGFACTORY!=NULL) {
            RS_DIALOGFACTORY->requestToolBar(RS2::ToolBarCircles);
        }
    }
}


// EOF
