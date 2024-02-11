
/*
 * File: GRectangle.h
 * --------------
 * This file defines three classes (GPoint, GRectangle, and GPolygon) that
 * are used in the graphics library to encapsulate basic geometrical
 * concepts.
 */

#ifndef _GRectangle_h
#define _GRectangle_h

#include <string>
#include <iostream>
// #include "error.h"
/*
 * Class: GRectangle
 * -----------------
 * This class represents a rectangle on the graphics plane and is
 * conventionally used to denote the bounding box for an object.
 */

class GRectangle
{
public:
    /*
     * Constructor: GRectangle
     * Usage: GRectangle empty;
     *        GRectangle r(x, y, width, height);
     * -----------------------------------------
     * Creates a GRectangle object with the specified components. If these parameters are
     * not supplied, the default constructor sets these fields
     * to 0.
     */
    GRectangle();
    GRectangle(double x, double y, double width, double height);


    /*
     * Method: getX
     * Usage: double x = r.getX();
     * ---------------------------
     * Returns the x component of the rectangle.
     */
    double getX() const;

    /*
     * Method: getY
     * Usage: double y = r.getY();
     * ---------------------------
     * Returns the y component of the rectangle.
     */

    double getY() const;

    /*
     * Method: getWidth
     * Usage: double width = r.getWidth();
     * -----------------------------------
     * Returns the width component of the rectangle.
     */

    double getWidth() const;

    /*
     * Method: getHeight
     * Usage: double height = r.getHeight();
     * -------------------------------------
     * Returns the height component of the rectangle.
     */
    double getHeight() const;


    /*
     * Method: isEmpty
     * Usage: if(r.isEmpty()) . . .
     * ----------------------------
     * Returns true if the rectangle is empty.
     */
    bool isEmpty() const;

    /*
     * Method: contains
     * Usage: if(r.contains(r)) . . .
     *        if(r.contains(x, y)) . . .
     * ----------------------------------
     * Returns true if the rectangle contains the given point, which may be
     * specified either as a point or as distinct coordinates.
     */
    // bool contains(GPoint pt) const;
    bool contains(double x, double y) const;

    /*
     * Method: toString
     * Usage: string str = r.toString();
     * ---------------------------------
     * Converts the GRectangle to a string in the form "(x, y, width, height)".
     */
    std::string toString() const;

private:
    double x, y;
    double width, height;
};

std::ostream & operator<<(std::ostream &os, GRectangle rect);

#endif
