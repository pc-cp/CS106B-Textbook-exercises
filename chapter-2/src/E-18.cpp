/* File: E-18.cpp
 * --------------
 * Write a graphics program to draw the Yin-Yang symbol
 * at the center of an empty graphics window.
 * Reference from: https://github.com/heavy3/programming-abstractions/blob/master/02-functions-and-libs/readerEx.02.18/main.cpp
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include "gmath.h"
#include "gwindow.h"

using namespace std;

enum SymbolColor
{
    LIGHT,
    DARK
};


const string LIGHT_COLOR = "WHITE";
const string DARK_COLOR = "BLACK";
const int SYMBOL_WIDTH = 400;
const int RADIUS = SYMBOL_WIDTH / 2;
const int EYE_WIDTH = 30;
const int MARGIN = 10;

const int WINDOW_WIDTH = 2 * (RADIUS + MARGIN);

const int WINDOW_HEIGHT = 2 * (RADIUS + MARGIN);
const int WINDOW_CENTER_X = WINDOW_WIDTH/2;
const int WINDOW_CENTER_Y = WINDOW_HEIGHT/2;
const int FLIP_Y_POLARITY = -1;
const int NUM_BODY_CIRCLES = 50;

/* Function prototype */
void drawTailChasers(GWindow *gw, SymbolColor color, int quality);
double getTailchaserBodyX0(double r, double R, double theta);
double getTailchaserBodyY0(double r, double R, double theta);
double getCircleTangentXsubT(double r, double theta);
double getCircleTangentYsubT(double r, double theta);
double toXScreenCoord(double xCartesianCoord);
double toYScreenCoord(double yCartesianCoord);
SymbolColor operator++(SymbolColor &color, int);
string toString(SymbolColor color);

/* Main Function*/
int main(void)
{
    GWindow *gw = new GWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    double x0 = MARGIN;
    double y0 = MARGIN;
    SymbolColor color = DARK;

    gw->setWindowTitle("yin-yang");

    gw->setColor(toString(color));
    gw->fillOval(x0, y0, SYMBOL_WIDTH, SYMBOL_WIDTH);

    color++;
    drawTailChasers(gw, color, NUM_BODY_CIRCLES);

    color++;
    gw->setColor(toString(color));
    gw->drawOval(x0, y0, SYMBOL_WIDTH, SYMBOL_WIDTH);
    return 0;
}

/*
 * Function: drawTailChasers
 * Usage: drawTailChasers(window, "WHITE", 20);
 * --------------------------------------------
 * We model the body of the tailchaser as a set of closely spaced,
 * filled circles that hug the inside of a larger circle in a 180 degree arc
 * that sweeps from north to south.
 *
 * The circles are rendered with the help of a graphics package that
 * describes the location of a circle in terms of a bounding box which circumscribes
 * the circle and has a reference origin in the upper
 * lefthand corner of the box.
 *
 * Generate a sequence of (x, y) points tangent to the outer circle
 * of the yin yang symbol, starting at the top and tracing a 180 degree
 * arc along the right side.
 *
 * Calculate the bounding boxes for the circular body segments
 * of one tailchaser. Render those circles as we sweep along a semi-circular path
 * to create a half-arc with rounded ends. Adding the head of the contrasting tail-chaser
 * at the end of the arc yields the effct two tail-chasers.
 */

void drawTailChasers(GWindow *gw, SymbolColor color, int quality)
{
    double R = (gw->getWidth() / 2.0) - MARGIN;
    double r = R / 2.0;
    int numBodyCircles = quality;
    double x0, y0;

    gw->setColor(toString(color));
    double deltaRadians = PI / numBodyCircles;

    for(double theta = PI/2; theta >= -PI/2; theta -= deltaRadians)
    {
        x0 = getTailchaserBodyX0(r, R, theta);
        y0 = getTailchaserBodyY0(r, R, theta);

        gw->fillOval(x0, y0, R, R);
    }
    color++;
    gw->setColor(toString(color));
    gw->fillOval(x0-1, y0, R, R);
    // gw->fillOval();
    gw->fillOval(WINDOW_CENTER_X-EYE_WIDTH/2, WINDOW_CENTER_Y-RADIUS/2-EYE_WIDTH/2, EYE_WIDTH, EYE_WIDTH);
    color++;
    gw->setColor(toString(color));
    gw->fillOval(WINDOW_CENTER_X-EYE_WIDTH/2, WINDOW_CENTER_Y+RADIUS/2-EYE_WIDTH/2, EYE_WIDTH, EYE_WIDTH);
}

double getCircleTangentXsubT(double rPixels, double thetaRadians)
{
    return rPixels * cos(thetaRadians);
}

double getCircleTangentYsubT(double rPixels, double thetaRadians)
{
    return rPixels * sin(thetaRadians);
}

double getTailchaserBodyX0(double r, double R, double theta)
{
    double xsubT = getCircleTangentXsubT(R, theta);

    // double tcRadiusScaling = 1 + sin(theta + PI/2);
    double tcRadiusScaling = 1 + cos(theta);

    double translate = r * tcRadiusScaling;

    return toXScreenCoord(xsubT - translate);
}

double getTailchaserBodyY0(double r, double R, double theta)
{
    double ysubT = getCircleTangentYsubT(R, theta);

    double tcRadiusScaling = 1 + cos(theta + PI / 2);
    double translate = r * tcRadiusScaling;

    return toYScreenCoord(ysubT + translate);
}

double toXScreenCoord(double xCartesianCoord)
{
    double cartesianOrigin = WINDOW_CENTER_X;
    double screenCoord = cartesianOrigin + xCartesianCoord;

    return screenCoord;
}

double toYScreenCoord(double yCartesianCoord)
{
    double cartesianOrigin = WINDOW_CENTER_Y;
    double screenCoord = cartesianOrigin + (FLIP_Y_POLARITY) * yCartesianCoord;

    return screenCoord;
}

SymbolColor operator++(SymbolColor & color, int)
{
    SymbolColor old = color;
    color = SymbolColor((old+1)%2);
    return color;
}

// SymbolColor operator++(SymbolColor& color, int);

string toString(SymbolColor color)
{
    string strColor;
    switch(color)
    {
        case LIGHT:
            strColor = LIGHT_COLOR;
            break;
        case DARK:
            strColor = DARK_COLOR;
            break;
        default:
            strColor = "unknown_color";
            break;
    }
    return strColor;
}
