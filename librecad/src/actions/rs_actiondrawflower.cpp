/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
**
** Copyright (C) 2010 R. van Twisk (librecad@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file gpl-2.0.txt included in the
** packaging of this file.
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

#include "rs_actiondrawflower.h"

#include <QAction>
#include "rs_dialogfactory.h"
#include "rs_graphicview.h"
#include "rs_commandevent.h"



RS_ActionDrawFlower::RS_ActionDrawFlower(RS_EntityContainer& container,
        RS_GraphicView& graphicView)
        :RS_PreviewActionInterface("Draw Flowers",
                           container, graphicView) {
    reset();
}



RS_ActionDrawFlower::~RS_ActionDrawFlower() {}


QAction* RS_ActionDrawFlower::createGUIAction(RS2::ActionType /*type*/, QObject* /*parent*/) {
/*RVT_PORT    QAction* action = new QAction(tr("Circle: Center, Point"),
                                  tr("Center, &Point"),
                                  QKeySequence(), NULL); */
        // "Circle: Center, Point"
    QAction* action = new QAction(tr("Flower"), NULL);
        action->setIcon(QIcon(":/extui/flower.png"));
    //action->zetStatusTip(tr("Draw circles with center and point"));
    return action;
}

void RS_ActionDrawFlower::reset() {
    data = RS_CircleData(RS_Vector(false), 0.0);
}



void RS_ActionDrawFlower::init(int status) {
    RS_PreviewActionInterface::init(status);

    reset();
}



void RS_ActionDrawFlower::trigger() {
    RS_PreviewActionInterface::trigger();

    RS_Circle* circle = new RS_Circle(container,
                                      data);
    circle->setLayerToActive();
    circle->setPenToActive();
    container->addEntity(circle);

  dataFlower.radius = data.radius;



   for(int i=0;i<=5;i++)
   {
        double radian = i*60* (M_PI/180.0);
        dataFlower.center.x = data.center.x + data.radius * cos(radian);
        dataFlower.center.y = data.center.y + data.radius * sin(radian);

        RS_Circle* flower = new RS_Circle(container,
                                      dataFlower);
        container->addEntity(flower);

       dataFlower.center.x=0;
       dataFlower.center.y=0;
   }


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

    RS_DEBUG->print("RS_ActionDrawFlower::trigger(): circle added: %d",
                    circle->getId());
}



void RS_ActionDrawFlower::mouseMoveEvent(QMouseEvent* e) {
    RS_DEBUG->print("RS_ActionDrawFlower::mouseMoveEvent begin");

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

    RS_DEBUG->print("RS_ActionDrawFlower::mouseMoveEvent end");
}



void RS_ActionDrawFlower::mouseReleaseEvent(QMouseEvent* e) {
    if (e->button()==Qt::LeftButton) {
        RS_CoordinateEvent ce(snapPoint(e));
        coordinateEvent(&ce);
    } else if (e->button()==Qt::RightButton) {
        deletePreview();
        init(getStatus()-1);
    }
}



void RS_ActionDrawFlower::coordinateEvent(RS_CoordinateEvent* e) {
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



void RS_ActionDrawFlower::commandEvent(RS_CommandEvent* e) {
    QString c = e->getCommand().toLower();

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



QStringList RS_ActionDrawFlower::getAvailableCommands() {
    QStringList cmd;
    return cmd;
}


void RS_ActionDrawFlower::updateMouseButtonHints() {
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



void RS_ActionDrawFlower::showOptions() {
    RS_ActionInterface::showOptions();
}



void RS_ActionDrawFlower::hideOptions() {
    RS_ActionInterface::hideOptions();
}



void RS_ActionDrawFlower::updateMouseCursor() {
    graphicView->setMouseCursor(RS2::CadCursor);
}



//void RS_ActionDrawFlower::updateToolBar() {
//    if (RS_DIALOGFACTORY!=NULL) {
//        if (isFinished()) {
//            RS_DIALOGFACTORY->resetToolBar();
//        }
//    }
//}


// EOF
