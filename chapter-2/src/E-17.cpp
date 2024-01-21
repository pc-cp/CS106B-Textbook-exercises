/* File: E-17.cpp
 * --------------
 * write a program that draws a checkerboard on the graphics window.
 */

#include <iostream>
#include "gwindow.h"
#include "gcolor.h"
using namespace std;

/* Prototype function */
void drawACheckerboard(GWindow *gw);

/* Main function*/
int main(void)
{
    GWindow* window = new GWindow(400, 400);
    drawACheckerboard(window);
    return 0;
}

void drawACheckerboard(GWindow *gw)
{
    gw->setTitle("Checkerboard");
    double width = gw->getWidth();
    double height = gw->getHeight();

    double squareWidth = width/8, squareHeight = height/8;
    double circleWidth = squareWidth-6, circleHeight = squareHeight-6;

    // i: row, j: col
    for(int i = 1; i <= 8; ++i)
    {
        for(int j = 1; j <= 8; ++j)
        {
            if(i <= 3)
            {
                if(i % 2 != 0 && j % 2 == 0)
                {
                    // gw->fillRect(x, y, width, height);
                    gw->setColor("GRAY");
                    gw->fillRect((j-1)*squareWidth, (i-1)*squareHeight, squareWidth, squareHeight);
                    gw->setColor("RED");
                    gw->fillOval((j-1)*squareWidth+3, (i-1)*squareHeight+3, circleWidth, circleHeight);
                }
                else if(i % 2 == 0 && j % 2 != 0)
                {
                    gw->setColor("GRAY");
                    gw->fillRect((j-1)*squareWidth, (i-1)*squareHeight, squareWidth, squareHeight);
                    gw->setColor("RED");
                    gw->fillOval((j-1)*squareWidth+3, (i-1)*squareHeight+3, circleWidth, circleHeight);
                }
            }
            else if(i >= 6)
            {
                if(i % 2 != 0 && j % 2 ==0)
                {
                    gw->setColor("GRAY");
                    gw->fillRect((j-1)*squareWidth, (i-1)*squareHeight, squareWidth, squareHeight);
                    gw->setColor("BLACK");
                    gw->fillOval((j-1)*squareWidth+3, (i-1)*squareHeight+3, circleWidth, circleHeight);

                }
                else if(i % 2 == 0 && j % 2 != 0)
                {
                    gw->setColor("GRAY");
                    gw->fillRect((j-1)*squareWidth, (i-1)*squareHeight, squareWidth, squareHeight);
                    gw->setColor("BLACK");
                    gw->fillOval((j-1)*squareWidth+3, (i-1)*squareHeight+3, circleWidth, circleHeight);
                }
            }
            else if(i > 3 && i < 6)
            {
                if(i % 2 != 0 && j % 2 ==0)
                {
                    gw->setColor("GRAY");
                    gw->fillRect((j-1)*squareWidth, (i-1)*squareHeight, squareWidth, squareHeight);
                }
                else if(i % 2 == 0 && j % 2 != 0)
                {
                    gw->setColor("GRAY");
                    gw->fillRect((j-1)*squareWidth, (i-1)*squareHeight, squareWidth, squareHeight);
                }
            }
        }
    }
}
