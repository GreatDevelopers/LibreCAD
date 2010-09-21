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


#ifndef RS_PAINTER_H
#define RS_PAINTER_H

#include "rs_color.h"
#include "rs_img.h"
#include "rs_math.h"
#include "rs_pen.h"
#include "rs_vector.h"
#include <qpolygon.h>



/**
 * This class is a common interface for a painter class. Such 
 * a class will in it's implementation be responsible to paint
 * lines, arcs, ... in widgets. All angles in rad.
 *
 * Note that this is just an interface used as a slot to 
 * communicate with the CADuntu from a GUI level. This 
 * does not contain any Qt or platform specific code.
 */
class RS_Painter {
public:
    RS_Painter() {
        drawingMode = RS2::ModeFull;
        offset = RS_Vector(0.0,0.0);
    }
    virtual ~RS_Painter() {}

    /**
     * Sets the drawing mode.
     */
    void setDrawingMode(RS2::DrawingMode m) {
        drawingMode = m;
    }

    /**
     * @return Current drawing mode.
     */
    RS2::DrawingMode getDrawingMode() {
        return drawingMode;
    }

	virtual void moveTo(int x, int y) = 0;
	virtual void lineTo(int x, int y) = 0;
	
    virtual void drawGridPoint(const RS_Vector& p) = 0;
    virtual void drawPoint(const RS_Vector& p) = 0;
    virtual void drawLine(const RS_Vector& p1, const RS_Vector& p2) = 0;
    virtual void drawRect(const RS_Vector& p1, const RS_Vector& p2);
    virtual void drawArc(const RS_Vector& cp, double radius,
                         double a1, double a2,
                         const RS_Vector& p1, const RS_Vector& p2,
                         bool reversed) = 0;
    virtual void drawArc(const RS_Vector& cp, double radius,
                         double a1, double a2,
                         bool reversed) = 0;
    void createArc(QPolygon& pa,
                   const RS_Vector& cp, double radius,
                   double a1, double a2,
                   bool reversed);
    virtual void drawCircle(const RS_Vector& cp, double radius) = 0;
    virtual void drawEllipse(const RS_Vector& cp,
                             double radius1, double radius2,
                             double angle,
                             double angle1, double angle2,
                             bool reversed) = 0;
	virtual void drawImg(RS_Img& img, const RS_Vector& pos, 
			double angle, const RS_Vector& factor,
			int sx, int sy, int sw, int sh) = 0;

    virtual void drawTextH(int x1, int y1, int x2, int y2,
                           const RS_String& text) = 0;
    virtual void drawTextV(int x1, int y1, int x2, int y2,
                           const RS_String& text) = 0;

    virtual void fillRect(int x1, int y1, int w, int h, const RS_Color& col) = 0;
	virtual void fillRect ( const QRectF & rectangle, const RS_Color & color ) = 0;
	virtual void fillRect ( const QRectF & rectangle, const QBrush & brush ) = 0;
	
    virtual void fillTriangle(const RS_Vector& p1,
                              const RS_Vector& p2,
                              const RS_Vector& p3) = 0;

	virtual void drawHandle(const RS_Vector& p, const RS_Color& c, int size=-1);

    virtual RS_Pen getPen() = 0;
    virtual void setPen(const RS_Pen& pen) = 0;
    virtual void setPen(const RS_Color& color) = 0;
    virtual void setPen(int r, int g, int b) = 0;
    virtual void disablePen() = 0;
	virtual void setBrush(const RS_Color& color) = 0;
	virtual void drawPolygon(const QPolygon& a) = 0;
	virtual void erase() = 0;
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;

    virtual void setOffset(const RS_Vector& o) {
        offset = o;
    }

    virtual void setClipRect(int x, int y, int w, int h) = 0;
    virtual void resetClipping() = 0;
    int toScreenX(double x) {
        return RS_Math::round(offset.x + x);
    }
    int toScreenY(double y) {
        return RS_Math::round(offset.y + y);
    }

protected:
    /**
     * Current drawing mode.
     */
    RS2::DrawingMode drawingMode;
    /**
     * A fixed offset added to all entities drawn (useful for previews).
     */
    RS_Vector offset;
};

#endif