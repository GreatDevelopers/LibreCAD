#include "rs_actiondrawnephroid.h"
#include <QAction>
#include "rs_dialogfactory.h"
#include "rs_graphicview.h"
#include "rs_commandevent.h"
#include "rs_point.h"



RS_ActionDrawNephroid::RS_ActionDrawNephroid(RS_EntityContainer& container,
                                       RS_GraphicView& graphicView)
        :RS_PreviewActionInterface("Draw Nephroid",
                           container, graphicView) {}


QAction* RS_ActionDrawNephroid::createGUIAction(RS2::ActionType /*type*/, QObject* /*parent*/) {
        // (tr("Points")
        QAction* action = new QAction(tr("&Nephroid"),  NULL);
        action->setIcon(QIcon(":/extui/6.png"));
    //action->zetStatusTip(tr("Draw Nephroids"));

    return action;
}


void RS_ActionDrawNephroid::trigger() {
    if (pt.valid) {


        RS_Point* point = new RS_Point(container, RS_PointData(pt));
        container->addEntity(point);
       float a=pt.x;
        float b=pt.y;
                float radius=10;

        for (float angle = 0;  angle <= 200; angle += 1)
                       {
           pt.x = pt.x + (radius * (3.0 * cos(angle) - cos(3.0*angle))+.5);
                  pt.y = pt.y + (radius * (3.0 * sin(angle) - sin(3.0*angle))+.5);

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



void RS_ActionDrawNephroid::mouseMoveEvent(QMouseEvent* e) {
    snapPoint(e);
}



void RS_ActionDrawNephroid::mouseReleaseEvent(QMouseEvent* e) {
    if (e->button()==Qt::LeftButton) {
        RS_CoordinateEvent ce(snapPoint(e));
        coordinateEvent(&ce);
    } else if (e->button()==Qt::RightButton) {
        init(getStatus()-1);
    }
}



void RS_ActionDrawNephroid::coordinateEvent(RS_CoordinateEvent* e) {
    if (e==NULL) {
        return;
    }

    RS_Vector mouse = e->getCoordinate();

    pt = mouse;
    trigger();
}



void RS_ActionDrawNephroid::commandEvent(RS_CommandEvent* e) {
    QString c = e->getCommand().toLower();

    if (checkCommand("help", c)) {
        if (RS_DIALOGFACTORY!=NULL) {
            RS_DIALOGFACTORY->commandMessage(msgAvailableCommands()
                                             + getAvailableCommands().join(", "));
        }
        return;
    }
}



QStringList RS_ActionDrawNephroid::getAvailableCommands() {
    QStringList cmd;
    return cmd;
}


void RS_ActionDrawNephroid::updateMouseButtonHints() {
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



void RS_ActionDrawNephroid::updateMouseCursor() {
    graphicView->setMouseCursor(RS2::CadCursor);
}



//void RS_ActionDrawNephroid::updateToolBar() {
//    if (RS_DIALOGFACTORY!=NULL) {
//        if (isFinished()) {
//            RS_DIALOGFACTORY->resetToolBar();
//        }
//    }
//}

// EOF
