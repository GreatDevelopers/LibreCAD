#ifndef RS_ACTIONDRAWCARDIOD_H
#define RS_ACTIONDRAWCARDIOD_H

#include "rs_previewactioninterface.h"


/**
 * This action class can handle user events to draw points.
 *
 * @author Jasleen Kaur (jasleen.7956@gmail.com)
 */
class RS_ActionDrawCardiod : public RS_PreviewActionInterface {
    Q_OBJECT
public:
    RS_ActionDrawCardiod(RS_EntityContainer& container,
                       RS_GraphicView& graphicView);
    ~RS_ActionDrawCardiod() {}

    static QAction* createGUIAction(RS2::ActionType /*type*/, QObject* /*parent*/);

    virtual RS2::ActionType rtti() {
        return RS2::ActionDrawCardiod;
    }
    virtual void trigger();

    virtual void mouseMoveEvent(QMouseEvent* e);
    virtual void mouseReleaseEvent(QMouseEvent* e);

    virtual void coordinateEvent(RS_CoordinateEvent* e);
    virtual void commandEvent(RS_CommandEvent* e);
        virtual QStringList getAvailableCommands();

    virtual void updateMouseButtonHints();
    virtual void updateMouseCursor();
//    virtual void updateToolBar();

private:
    RS_Vector pt;
};

#endif // RS_ACTIONDRAWCARDIOD_H
