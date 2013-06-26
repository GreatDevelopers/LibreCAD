#include "rs_actiondrawcardiod.h"

#include <QAction>
#include "rs_dialogfactory.h"
#include "rs_graphicview.h"
#include "rs_commandevent.h"
#include "rs_point.h"



RS_ActionDrawCardiod::RS_ActionDrawCardiod(RS_EntityContainer& container,
                                       RS_GraphicView& graphicView)
        :RS_PreviewActionInterface("Draw Cardiod",
                           container, graphicView) {}


QAction* RS_ActionDrawCardiod::createGUIAction(RS2::ActionType /*type*/, QObject* /*parent*/) {
        // (tr("Points")
        QAction* action = new QAction(tr("&Cardiod"),  NULL);
        action->setIcon(QIcon(":/extui/3.png"));
    //action->zetStatusTip(tr("Draw Points"));

    return action;
}


void RS_ActionDrawCardiod::trigger() {
    if (pt.valid) {


        RS_Point* point = new RS_Point(container, RS_PointData(pt));
        container->addEntity(point);
       float a=pt.x;
        float b=pt.y;
                float radius = 10;

        for (float angle = 0;  angle <= 200; angle += 1)
                       {
            pt.x = pt.x + radius * (2.0*cos(angle) - cos(2.0*angle))+.5;
                  pt.y = pt.y + radius * (2.0*sin(angle) - sin(2.0*angle))+.5;

                        RS_Point* point1 = new RS_Point(container, RS_PointData(pt));
                   container->addEntity(point1);
                   pt.x = a;
                   pt.y = b;


                }



        if (document) {
            document->startUndoCycle();
            document->addUndoable(point);
            document->endUndoCycle();
        }

                graphicView->redraw(RS2::RedrawDrawing);
        graphicView->moveRelativeZero(pt);
    }
}



void RS_ActionDrawCardiod::mouseMoveEvent(QMouseEvent* e) {
    snapPoint(e);
}



void RS_ActionDrawCardiod::mouseReleaseEvent(QMouseEvent* e) {
    if (e->button()==Qt::LeftButton) {
        RS_CoordinateEvent ce(snapPoint(e));
        coordinateEvent(&ce);
    } else if (e->button()==Qt::RightButton) {
        init(getStatus()-1);
    }
}



void RS_ActionDrawCardiod::coordinateEvent(RS_CoordinateEvent* e) {
    if (e==NULL) {
        return;
    }

    RS_Vector mouse = e->getCoordinate();

    pt = mouse;
    trigger();
}



void RS_ActionDrawCardiod::commandEvent(RS_CommandEvent* e) {
    QString c = e->getCommand().toLower();

    if (checkCommand("help", c)) {
        if (RS_DIALOGFACTORY!=NULL) {
            RS_DIALOGFACTORY->commandMessage(msgAvailableCommands()
                                             + getAvailableCommands().join(", "));
        }
        return;
    }
}



QStringList RS_ActionDrawCardiod::getAvailableCommands() {
    QStringList cmd;
    return cmd;
}


void RS_ActionDrawCardiod::updateMouseButtonHints() {
    if (RS_DIALOGFACTORY!=NULL) {
        switch (getStatus()) {
        case 0:
            RS_DIALOGFACTORY->updateMouseWidget(tr("Specify location"), tr("Cancel"));
            break;
        default:
            RS_DIALOGFACTORY->updateMouseWidget("", "");
            break;
        }
    }
}



void RS_ActionDrawCardiod::updateMouseCursor() {
    graphicView->setMouseCursor(RS2::CadCursor);
}



//void RS_ActionDrawCardiod::updateToolBar() {
//    if (RS_DIALOGFACTORY!=NULL) {
//        if (isFinished()) {
//            RS_DIALOGFACTORY->resetToolBar();
//        }
//    }
//}

// EOF
