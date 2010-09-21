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


#ifndef RS_ENTITYCONTAINER_H
#define RS_ENTITYCONTAINER_H

#include "rs_arc.h"
#include "rs_circle.h"
#include "rs_ellipse.h"
#include "rs_entity.h"
#include "rs_line.h"
#include "rs_point.h"
#include "rs_ptrlist.h"

/**
 * Class representing a tree of entities.
 * Typical entity containers are graphics, polylines, groups, texts, ...)
 *
 * @author Andrew Mustun
 */
class RS_EntityContainer : public RS_Entity {

public:

    RS_EntityContainer(RS_EntityContainer* parent=NULL, bool owner=true);
    //RS_EntityContainer(const RS_EntityContainer& ec);
    virtual ~RS_EntityContainer();

    virtual RS_Entity* clone();
    virtual void detach();

    /** @return RS2::EntityContainer */
    virtual RS2::EntityType rtti() const {
        return RS2::EntityContainer;
    }
	
    void reparent(RS_EntityContainer* parent);

    /**
     * @return true: because entities made from this class
     *         and subclasses are containers for other entities.
     */
    virtual bool isContainer() const {
        return true;
    }
	
    /**
     * @return false: because entities made from this class
     *         and subclasses are containers for other entities.
     */
    virtual bool isAtomic() const {
		return false;
	}
	
	virtual double getLength();

    virtual void undoStateChanged(bool undone);
    virtual void setVisible(bool v);

    virtual bool setSelected(bool select=true);
    virtual bool toggleSelected();

    virtual void selectWindow(RS_Vector v1, RS_Vector v2, 
		bool select=true, bool cross=false);

    virtual void addEntity(RS_Entity* entity);
    virtual void insertEntity(int index, RS_Entity* entity);
    virtual void replaceEntity(int index, RS_Entity* entity);
    virtual bool removeEntity(RS_Entity* entity);
    virtual RS_Entity* firstEntity(RS2::ResolveLevel level=RS2::ResolveNone);
    virtual RS_Entity* lastEntity(RS2::ResolveLevel level=RS2::ResolveNone);
    virtual RS_Entity* nextEntity(RS2::ResolveLevel level=RS2::ResolveNone);
    virtual RS_Entity* prevEntity(RS2::ResolveLevel level=RS2::ResolveNone);
	virtual RS_Entity* entityAt(uint index);
	virtual RS_Entity* currentEntity();
	virtual int entityAt();
	virtual int findEntity(RS_Entity* entity);
    virtual void clear();

	RS_PtrListIterator<RS_Entity> createIterator();

    //virtual unsigned long int count() {
	//	return count(false);
	//}
    virtual bool isEmpty() {
        return count()==0;
    }
    virtual unsigned long int count();
    virtual unsigned long int countDeep();
    //virtual unsigned long int countLayerEntities(RS_Layer* layer);
    virtual unsigned long int countSelected();

    /**
     * Enables / disables automatic update of borders on entity removals
     * and additions. By default this is turned on.
     */
    virtual void setAutoUpdateBorders(bool enable) {
        autoUpdateBorders = enable;
    }
    virtual void adjustBorders(RS_Entity* entity);
    virtual void calculateBorders();
    virtual void forcedCalculateBorders();
    virtual void updateDimensions();
    virtual void updateInserts();
    virtual void updateSplines();
    virtual void update();
	virtual void renameInserts(const RS_String& oldName, 
		const RS_String& newName);


    virtual RS_Vector getNearestEndpoint(const RS_Vector& coord,
                                         double* dist = NULL);

    RS_Entity* getNearestEntity(const RS_Vector& point,
                                double* dist = NULL,
                                RS2::ResolveLevel level=RS2::ResolveAll);

    virtual RS_Vector getNearestPointOnEntity(const RS_Vector& coord,
            bool onEntity = true,
			double* dist = NULL,
            RS_Entity** entity=NULL);

    virtual RS_Vector getNearestCenter(const RS_Vector& coord,
                                       double* dist = NULL);
    virtual RS_Vector getNearestMiddle(const RS_Vector& coord,
                                       double* dist = NULL);
    virtual RS_Vector getNearestDist(double distance,
                                     const RS_Vector& coord,
                                     double* dist = NULL);
    virtual RS_Vector getNearestIntersection(const RS_Vector& coord,
            double* dist = NULL);
    virtual RS_Vector getNearestRef(const RS_Vector& coord,
                                     double* dist = NULL);
    virtual RS_Vector getNearestSelectedRef(const RS_Vector& coord,
                                     double* dist = NULL);
			
    virtual double getDistanceToPoint(const RS_Vector& coord,
                                      RS_Entity** entity,
                                      RS2::ResolveLevel level=RS2::ResolveNone,
				      double solidDist = RS_MAXDOUBLE);

    virtual bool optimizeContours();
	
	virtual bool hasEndpointsWithinWindow(RS_Vector v1, RS_Vector v2);
	
	virtual void move(RS_Vector offset);
    virtual void rotate(RS_Vector center, double angle);
    virtual void scale(RS_Vector center, RS_Vector factor);
    virtual void mirror(RS_Vector axisPoint1, RS_Vector axisPoint2);
	
    virtual void stretch(RS_Vector firstCorner,
                         RS_Vector secondCorner,
                         RS_Vector offset);
	virtual void moveRef(const RS_Vector& ref, const RS_Vector& offset);
	virtual void moveSelectedRef(const RS_Vector& ref, const RS_Vector& offset);

    virtual void draw(RS_Painter* painter, RS_GraphicView* view, double patternOffset=0.0);

    friend std::ostream& operator << (std::ostream& os, RS_EntityContainer& ec);

	bool isOwner() {return entities.autoDelete();}
	void setOwner(bool owner) {return entities.setAutoDelete(owner);}
protected:

    /** entities in the container */
    RS_PtrList<RS_Entity> entities;

    /** sub container used only temporarly for iteration. */
    RS_EntityContainer* subContainer;

    /**
     * Automatically update the borders of the container when entities
     * are added or removed. 
     */
    static bool autoUpdateBorders;
}
;


#endif