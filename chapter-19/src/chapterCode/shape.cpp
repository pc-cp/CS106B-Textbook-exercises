
/*
 * File: shape.cpp
 * ---------------
 * This file implements the shape.h interface.
 */

#include <string>
#include "gwindow.h"
#include "shape.h"
using namespace std;

/*
 * Implementation notes: Shape class
 * ---------------------------------
 * The constructor for the superclass sets all shapes to BLACK, which is the
 * default color. The remaining methods simply set the instance variables.
 */

Shape::Shape() {
    setColor("BLACK");
}

void Shape::setLocation(double x, double y) {
    this->x = x;
    this->y = y;
}

void Shape::move(double x, double y) {
    this->x += x;
    this->y += y;
}

void Shape::setColor(string color) {
    this->color = color;
}

/*
 * Implementation notes: Line class
 * --------------------------------
 * The constructor for the Line class has to change the specification
 * of the line from the endpoints passed to the constructor to the
 * representation that uses a starting point along with dx/dy values.
 */

Line::Line(double x1, double y1, double x2, double y2) {
    this->x = x1;
    this->y = y1;
    this->dx = x2 - x1;
    this->dy = y2 - y1;
}

void Line::draw(GWindow &gw) {
    gw.setColor(color);
    gw.drawLine(x, y, x+dx, y+dy);
}

/*
 * Implementation notes: Rect and Oval classes
 * -------------------------------------------
 * The constructors for these classes store their arguments in the
 * corresponding instance variables. The draw method for the shape
 * just forwards the request to the GWindow class.
 */

Rect::Rect(double x, double y, double width, double height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Rect::draw(GWindow &gw) {
    gw.setColor(color);
    gw.fillRect(x, y, width, height);
}


Oval::Oval(double x, double y, double width, double height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Oval::draw(GWindow &gw) {
    gw.setColor(color);
    gw.fillOval(x, y, width, height);
}

/*
 * Implementation notes: Circle
 * ----------------------------
 * The Circle class is a subclass of Oval that interprets for which
 * the constructor interprets its arguments in a different way. This
 * constructor uses an initialization list to call the Oval constructor
 * with the correct arguments.
 */

Circle::Circle(double x, double y, double r) : Oval(x-r, y-r, 2*r, 2*r){
    /* Empty */
}

