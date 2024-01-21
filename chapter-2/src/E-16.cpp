/* File: E-16.cpp
 * --------------
 * Use the graphics library to draw a rainbow
 */

#include <iostream>
#include "gwindow.h"

using namespace std;

/* Prototype function */
void drawARainbow(GWindow *gw);

/* Main function*/
int main(void)
{
    GWindow* window = new GWindow(700, 300);
    drawARainbow(window);
    return 0;
}

void drawARainbow(GWindow *gw)
{
    gw->setTitle("Rainbow");
    double width = gw->getWidth();
    double height = gw->getHeight();
    double intervals = height/20 * 2;
    // cout << width << " , " << height << endl;
    gw->setColor("CYAN");
    gw->fillRect(0, 0, width, height);

    gw->setColor("RED");
    gw->fillOval(-width/10, height/20, 1.2*width, 2*height);
    gw->setColor("ORANGE");
    gw->fillOval(-width/10, height/20 + intervals, 1.2*width, 2*height);
    gw->setColor("YELLOW");
    gw->fillOval(-width/10, height/20 + intervals * 2 , 1.2*width, 2*height);
    gw->setColor("GREEN");
    gw->fillOval(-width/10, height/20 + intervals * 3 , 1.2*width, 2*height);
    gw->setColor("BLUE");
    gw->fillOval(-width/10, height/20 + intervals * 4 , 1.2*width, 2*height);
    gw->setColor("MAGENTA");
    gw->fillOval(-width/10, height/20 + intervals * 5 , 1.2*width, 2*height);
    gw->setColor("CYAN");
    gw->fillOval(-width/10, height/20 + intervals * 6 , 1.2*width, 2*height);
}
