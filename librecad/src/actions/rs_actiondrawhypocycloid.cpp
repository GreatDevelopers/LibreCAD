#include "rs_actiondrawhypocycloid.h"
#include <QAction>
#include "rs_dialogfactory.h"
#include "rs_graphicview.h"
#include "rs_commandevent.h"
#include "rs_point.h"



RS_ActionDrawHypocycloid::RS_ActionDrawHypocycloid(RS_EntityContainer& container,
                                       RS_GraphicView& graphicView)
        :RS_PreviewActionInterface("Draw Hypocycloid",
                           container, graphicView) {}


QAction* RS_ActionDrawHypocycloid::createGUIAction(RS2::ActionType /*type*/, QObject* /*parent*/) {
        // (tr("Points")
        QAction* action = new QAction(tr("&Hypocycloid"),  NULL);
        action->setIcon(QIcon(":/extui/5.png"));
    //action->zetStatusTip(tr("Draw Hypocycloid"));

    return action;
}


void RS_ActionDrawHypocycloid::trigger() {
    if (pt.valid) {


        RS_Point* point = new RS_Point(container, RS_PointData(pt));
        container->addEntity(point);
       float a=pt.x;
        float b=pt.y;
                float radius2=5,radius1=4*radius2;

        for (float angle = 0;  angle <= 200; angle += 1)
                       {
            pt.x  = pt.x + ((radius1- radius2) * cos(angle)) + (radius2 * cos((radius1/radius2 - 1.0)*angle));
                   pt.y = pt.y + ((radius1- radius2) * sin(angle)) - (radius2 * sin((radius1/radius2 - 1.0)*angle));


                        RS_Point* point1 = new RS_Point(container, RS_PointData(pt));
                   container->addEntity(point1);
                   pt.x =a;
                   pt.y=b;


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



void RS_ActionDrawHypocycloid::mouseMoveEvent(QMouseEvent* e) {
    snapPoint(e);
}



void RS_ActionDrawHypocycloid::mouseReleaseEvent(QMouseEvent* e) {
    if (e->button()==Qt::LeftButton) {
        RS_CoordinateEvent ce(snapPoint(e));
        coordinateEvent(&ce);
    } else if (e->button()==Qt::RightButton) {
        init(getStatus()-1);
    }
}



void RS_ActionDrawHypocycloid::coordinateEvent(RS_CoordinateEvent* e) {
    if (e==NULL) {
        return;
    }

    RS_Vector mouse = e->getCoordinate();

    pt = mouse;
    trigger();
}



void RS_ActionDrawHypocycloid::commandEvent(RS_CommandEvent* e) {
    QString c = e->getCommand().toLower();

    if (checkCommand("help", c)) {
        if (RS_DIALOGFACTORY!=NULL) {
            RS_DIALOGFACTORY->commandMessage(msgAvailableCommands()
                                             + getAvailableCommands().join(", "));
        }
        return;
    }
}



QStringList RS_ActionDrawHypocycloid::getAvailableCommands() {
    QStringList cmd;
    return cmd;
}


void RS_ActionDrawHypocycloid::updateMouseButtonHints() {
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



void RS_ActionDrawHypocycloid::updateMouseCursor() {
    graphicView->setMouseCursor(RS2::CadCursor);
}



//void RS_ActionDrawHypocycloid::updateToolBar() {
//    if (RS_DIALOGFACTORY!=NULL) {
//        if (isFinished()) {
//            RS_DIALOGFACTORY->resetToolBar();
//        }
//    }
//}

// EOF
