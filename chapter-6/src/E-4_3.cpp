
/*
 * PegBoard.cpp
 *
 * This file implements the PegBoard.h interface.
 * ----------------------------------------------
 */
#include <sstream>
#include "PegBoard.h"
#include "random.h"

// Constants and types

const std::string DFLT_TITLE = "YarnPattern";
const int MIN_NUM_PEGS = 2; // Mininum number required pegs along 1 dimension.

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * The default constructor is provided so other initialized peg boards
 * can be assigned to objects instantiated through this constructor.
 *
 * The non-default constructor takes and number of pegs in the horizontal and
 * vertical dimensions and creates a viable peg board with a fully
 * initialized vector of pegs and their (x, y) positions in the graphic window.
 *
 * A runtime error halts execution if too few (i.e., < 2) pegs are specified
 * in either dimension.
 */

PegBoard::PegBoard() { }

PegBoard::PegBoard(int pegsAcross, int pegsDown)
{
    gw.setWindowTitle(DFLT_TITLE);
    if(pegsAcross < MIN_NUM_PEGS || pegsDown < MIN_NUM_PEGS)
    {
        std::ostringstream os;
        os << "PegBoard: Need at least " << MIN_NUM_PEGS << " pegs across "
           << " and down.";
        error(os.str());
    }

    pegsA = pegsAcross;
    pegsD = pegsDown;

    positionPegs();
}

/*
 * Implementation notes: Destructor
 * --------------------------------
 * Enforce an orderly shutdown of graphics resources when peg board objects
 * are destroyed using a free function from the GWindow.h interface.
 */

PegBoard::~PegBoard()
{
    exitGraphics();
}

/*
 * Implementation notes: clear
 * ---------------------------
 * Clear the image currently displayed in the graphics window using the
 * primitive from the GWindow.h interface.
 */

void PegBoard::clear()
{
    gw.clear();
}

/*
 * Implementation notes: draw
 * --------------------------
 * Render a complete image on the peg board using the specified peg delta
 * and color preference passed in as reference variables.
 *
 * Requires a suitably initialized Vector of peg position typically
 * accomplished in the constructor through a call to positionsPegs().
 */

void PegBoard::draw(int pegDelta, ColorT color)
{
    if(color != RANDOM)
    {
        gw.setColor(colorToString(color));
    }
    for(int iPegIndex = 0; iPegIndex < pegs.size(); iPegIndex++)
    {
        int jPegIndex = (iPegIndex + pegDelta) % pegs.size();
        if(jPegIndex < 0)
        {   // Handle negative pegDelta (counter-clockwise).
            jPegIndex += pegs.size();
        }
        if(color == RANDOM)
        {
            ColorT randomColor = ColorT(randomInteger(0, RANDOM-1));
            std::string colorStr = colorToString(randomColor);
            gw.setColor(colorStr);
        }
        gw.drawLine(pegs[iPegIndex], pegs[jPegIndex]);
    }
}

/*
 * Implementation notes: colorToString
 * -----------------------------------
 * Convert between the enumerated type of predefined colors (exported
 * by the PegBoard.h interface) and the string names expected by the GWindow.h
 * interface.
 */

std::string PegBoard::colorToString(ColorT color)
{
    switch(color)
    {
    case BLACK: return "BLACK";
    case BLUE:  return "BLUE";
    case CYAN:  return "CYAN";
    case DARK_GRAY: return "DARK_GRAY";
    case GRAY:  return "GRAY";
    case GREEN: return "GREEN";
    case LIGHT_GRAY: return "LIGHT_GRAY";
    case MAGENTA: return "MAGENTA";
    case ORANGE: return "ORANGE";
    case PINK: return "PINK";
    case RED:   return "RED";
    case YELLOW: return "YELLOW";
    default: return "BLACK";
    }
}


/*
 * Implementation notes: positionPegs
 * ----------------------------------
 * Position the pegs along the board perimeter relative to the dimensions
 * of the graphics window. The pegs themselves are not rendered visually,
 * but their associated x and y coordinates feed into the draw() method
 * as line endpoints.
 *
 * This routine should be called if the model is enhanced to respond to
 * window resize events.
 */

void PegBoard::positionPegs()
{
    pegs.clear();

    /*
     * Calculate the segment distance between two adjacent pegs.
     * This may differ for pegs across the horizontal versus down
     * the vertical.
     */

    double segmentA = gw.getWidth() / double(pegsA - 1);
    double segmentD = gw.getHeight() / double(pegsD - 1);

    /*
     * Position the pegs clockwise around the perimeter of the board,
     * accounting for the shared peg in each corner.
     *
     * Start with peg '0' in the upper lefthand corner of the
     * graphics window.
     */

    double x = 0.0;
    double y = 0.0;

    for(int col = 1; col <= pegsA; col++)
    {
        x = (col - 1) * segmentA;
        pegs.add(GPoint(x, y));
    }

    for(int row = 1; row <= pegsD; row++)
    {
        y = row * segmentD;
        pegs.add(GPoint(x, y));
    }

    for(int col = 1; col < pegsA; col++)
    {
        x -= segmentA;
        pegs.add(GPoint(x, y));
    }

    for(int row = 1; row < (pegsD - 1); row++)
    {
        y -= segmentD;
        pegs.add(GPoint(x, y));
    }
}
