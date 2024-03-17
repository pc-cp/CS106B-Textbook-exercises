
// https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1224/assignments/a3/
// Part One: The Sierpinski Triangle

#include "Sierpinski.h"
#include "error.h"
using namespace std;

/**
 * Draws a triangle with the specified corners in the specified window. Feel free
 * to edit this function as you see fit to change things like color, fill style,
 * etc. in whatever way you'd like!
 *
 * @param window The window in which to draw the triangle.
 * @param x0 y0 The first corner of the triangle.
 * @param x1 y1 The second corner of the triangle.
 * @param x2 y2 The third corner of the triangle.
 */
void drawTriangle(GWindow& window,
                  double x0, double y0,
                  double x1, double y1,
                  double x2, double y2) {
    window.setColor("black");
    window.fillPolygon({ x0, y0, x1, y1, x2, y2 });
}

void drawSierpinskiTriangle(GWindow& window,
                            double x0, double y0,
                            double x1, double y1,
                            double x2, double y2,
                            int order) {
    if(order < 0) {
        error("order must greater or equal zero.");
    }
    else if(order == 0) {
        drawTriangle(window, x0, y0, x1, y1, x2, y2);
    }
    else {
        double middleX01 = (x0 + x1) / 2;
        double middleY01 = (y0 + y1) / 2;
        double middleX02 = (x0 + x2) / 2;
        double middleY02 = (y0 + y2) / 2;
        double middleX12 = (x1 + x2) / 2;
        double middleY12 = (y1 + y2) / 2;

        drawSierpinskiTriangle(window,
                               x0, y0,
                               middleX01, middleY01,
                               middleX02, middleY02,
                               order-1);
        drawSierpinskiTriangle(window,
                               middleX01, middleY01,
                               x1, y1,
                               middleX12, middleY12,
                               order-1);
        drawSierpinskiTriangle(window,
                               middleX02, middleY02,
                               middleX12, middleY12,
                               x2, y2,
                               order-1);
    }
}
