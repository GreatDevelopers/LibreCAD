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

#include "rs_actiondrawroom.h"

#include <QAction>
#include "rs_dialogfactory.h"
#include "rs_graphicview.h"
#include "rs_commandevent.h"



RS_ActionDrawRoom::RS_ActionDrawRoom(
    RS_EntityContainer& container,
    RS_GraphicView& graphicView)
        :RS_PreviewActionInterface("Draw rectangles",
                           container, graphicView) {
    reset();
}



RS_ActionDrawRoom::~RS_ActionDrawRoom() {}

QAction* RS_ActionDrawRoom::createGUIAction(RS2::ActionType /*type*/, QObject* /*parent*/) {
        //  tr("&Rectangle"),
        QAction* action = new QAction(tr("Room"), NULL);
        action->setIcon(QIcon(":/extui/1.png"));
    //action->zetStatusTip(tr("Draw rectangles"));
        return action;
}


void RS_ActionDrawRoom::reset() {
    for (int i=0; i<4; ++i) {
        data[i] = RS_LineData(RS_Vector(false),
                              RS_Vector(false));
        cornerRoom1.x=corner1.x;
        cornerRoom1.y=corner1.y;
        cornerRoom2.x=corner2.x;
        cornerRoom2.y=corner2.y;
    }
}



void RS_ActionDrawRoom::init(int status) {
    RS_PreviewActionInterface::init(status);

    reset();
}



void RS_ActionDrawRoom::trigger() {
    RS_PreviewActionInterface::trigger();

    RS_Line* line[4];
    preparePreview(corner1.x, corner1.y, corner2.x, corner2.y);

    // create and add rectangle:
    for (int i=0; i<4; ++i) {
        //front outer
        line[i] = new RS_Line(container,
                              data[i]);
        line[i]->setLayerToActive();
        line[i]->setPenToActive();
        container->addEntity(line[i]);
    }
    double depth = (corner2.x - corner1.x)/2, gap = (corner1.y - corner2.y)/2, t = 3;  //width

 for(int i=0;i<4;i++)
       {   //front inner rectangle
           //Top View
     reset();
               preparePreview(cornerRoom1.x - t, cornerRoom1.y + t, cornerRoom2.x + t, cornerRoom2.y - t);
               line[i] = new RS_Line(container,
                                    data[i]);
               container->addEntity(line[i]);
               reset();

           }

//.................................................................................................................
//Right Side Veiw
 for(int i=0; i<=3; i++)
 {
     //outer
cornerRoom2.x+=gap;

     dataRoom[0] = RS_LineData(RS_Vector(cornerRoom2.x, cornerRoom1.y), RS_Vector(cornerRoom2.x + depth, cornerRoom1.y));
     dataRoom[1] = RS_LineData(RS_Vector(cornerRoom2.x, cornerRoom1.y), RS_Vector(cornerRoom2.x, cornerRoom2.y));
     dataRoom[2] = RS_LineData(RS_Vector(cornerRoom2.x, cornerRoom2.y), RS_Vector(cornerRoom2.x + depth, cornerRoom2.y));


        line[i] = new RS_Line(container,
                              dataRoom[i]);
         container->addEntity(line[i]);
         reset();
 }



 for(int i=0; i<=3; i++)
 {  //side inner veiw
     cornerRoom2.x+=gap;
     dataRoom[0] = RS_LineData(RS_Vector(cornerRoom2.x - t, cornerRoom1.y + t), RS_Vector(cornerRoom2.x + depth, cornerRoom1.y + t));
     dataRoom[1] = RS_LineData(RS_Vector(cornerRoom2.x - t, cornerRoom1.y + t), RS_Vector(cornerRoom2.x - t, cornerRoom2.y - t));
     dataRoom[2] = RS_LineData(RS_Vector(cornerRoom2.x - t, cornerRoom2.y - t), RS_Vector(cornerRoom2.x + depth, cornerRoom2.y - t));


        line[i] = new RS_Line(container,
                              dataRoom[i]);
         container->addEntity(line[i]);
         reset();
 }



//................................................................................................................
// Front View

 for(int i=0; i<=3; i++)
  {
      //outer


      dataRoom[0] = RS_LineData(RS_Vector(cornerRoom1.x, cornerRoom2.y - gap), RS_Vector(cornerRoom2.x , cornerRoom2.y - gap));
      dataRoom[1] = RS_LineData(RS_Vector(cornerRoom2.x, cornerRoom2.y - gap), RS_Vector(cornerRoom2.x , cornerRoom2.y - gap - depth));
      dataRoom[2] = RS_LineData(RS_Vector(cornerRoom1.x -t , cornerRoom2.y - gap - depth), RS_Vector(cornerRoom2.x + t , cornerRoom2.y - gap - depth)  );
      dataRoom[3] = RS_LineData(RS_Vector(cornerRoom1.x, cornerRoom2.y - gap - depth), RS_Vector(cornerRoom1.x, cornerRoom2.y - gap ));


         line[i] = new RS_Line(container,
                               dataRoom[i]);
          container->addEntity(line[i]);
          reset();
  }


  for(int i=0; i<=2; i++)
  {  //inner
      dataRoom[0] = RS_LineData(RS_Vector(cornerRoom1.x - t, cornerRoom2.y - gap + t), RS_Vector(cornerRoom2.x + t , cornerRoom2.y - gap + t));
      dataRoom[1] = RS_LineData(RS_Vector(cornerRoom2.x + t, cornerRoom2.y - gap + t), RS_Vector(cornerRoom2.x + t , cornerRoom2.y - gap - depth));
      dataRoom[2] = RS_LineData(RS_Vector(cornerRoom1.x - t, cornerRoom2.y - gap - depth), RS_Vector(cornerRoom1.x - t, cornerRoom2.y - gap + t ));


         line[i] = new RS_Line(container,
                               dataRoom[i]);
          container->addEntity(line[i]);
          reset();
  }


//.................................................................................................................

    // upd. undo list:
    if (document!=NULL) {
        document->startUndoCycle();
        for (int i=0; i<4; ++i) {
            document->addUndoable(line[i]);
        }
        document->endUndoCycle();
    }

    // upd. view
        graphicView->redraw(RS2::RedrawDrawing);
    graphicView->moveRelativeZero(corner2);
}



void RS_ActionDrawRoom::mouseMoveEvent(QMouseEvent* e) {
    RS_DEBUG->print("RS_ActionDrawRoom::mouseMoveEvent begin");

    RS_Vector mouse = snapPoint(e);
    if (getStatus()==SetCorner2 && corner1.valid) {
        corner2 = mouse;
        deletePreview();

        preparePreview(corner1.x, corner1.y, corner2.x, corner2.y);

        for (int i=0; i<4; ++i) {
            preview->addEntity(new RS_Line(preview, data[i]));
        }
        drawPreview();
    }

    RS_DEBUG->print("RS_ActionDrawRoom::mouseMoveEvent end");
}


void RS_ActionDrawRoom::mouseReleaseEvent(QMouseEvent* e) {
    if (e->button()==Qt::LeftButton) {
        RS_CoordinateEvent ce(snapPoint(e));
        coordinateEvent(&ce);
    } else if (e->button()==Qt::RightButton) {
        deletePreview();
        init(getStatus()-1);
    }
}



void RS_ActionDrawRoom::preparePreview(double x1, double y1, double x2, double y2) {
    data[0] = RS_LineData(RS_Vector(x1, y1), RS_Vector(x2, y1));
    data[1] = RS_LineData(RS_Vector(x2, y1), RS_Vector(x2, y2));
    data[2] = RS_LineData(RS_Vector(x2, y2), RS_Vector(x1, y2));
    data[3] = RS_LineData(RS_Vector(x1, y2), RS_Vector(x1, y1));

}


void RS_ActionDrawRoom::coordinateEvent(RS_CoordinateEvent* e) {
    if (e==NULL) {
        return;
    }

    RS_Vector mouse = e->getCoordinate();

    switch (getStatus()) {
    case SetCorner1:
        corner1 = mouse;
        graphicView->moveRelativeZero(mouse);
        setStatus(SetCorner2);
        break;

    case SetCorner2:
        corner2 = mouse;
        trigger();
        setStatus(SetCorner1);
        break;

    default:
        break;
    }
}



void RS_ActionDrawRoom::commandEvent(RS_CommandEvent* e) {
    QString c = e->getCommand().toLower();

    if (checkCommand("help", c)) {
        if (RS_DIALOGFACTORY!=NULL) {
            RS_DIALOGFACTORY->commandMessage(msgAvailableCommands()
                                             + getAvailableCommands().join(" , "));
        }
        return;
    }
}



QStringList RS_ActionDrawRoom::getAvailableCommands() {
    QStringList cmd;
    return cmd;
}




void RS_ActionDrawRoom::updateMouseButtonHints() {
    if (RS_DIALOGFACTORY!=NULL) {
        switch (getStatus()) {



        case SetCorner1:
            RS_DIALOGFACTORY->updateMouseWidget(tr("Specify first corner"),
                                                tr("Cancel"));
            break;
        case SetCorner2:
            RS_DIALOGFACTORY->updateMouseWidget(tr("Specify second corner"),
                                                tr("Back"));
            break;
        default:
            RS_DIALOGFACTORY->updateMouseWidget("", "");
            break;
        }
    }
}


void RS_ActionDrawRoom::updateMouseCursor() {
    graphicView->setMouseCursor(RS2::CadCursor);
}


//void RS_ActionDrawRoom::updateToolBar() {
//    if (RS_DIALOGFACTORY!=NULL) {
//        if (isFinished()) {
//            RS_DIALOGFACTORY->resetToolBar();
//        }
//    }
//}

// EOF

