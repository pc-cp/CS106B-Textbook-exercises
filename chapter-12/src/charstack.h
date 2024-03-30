
/*
 * File: charstack.h
 * -----------------
 * This interface defines the CharStack class, which implements the stack abstraction for characters.
 */

#ifndef _charstack_h
#define _charstack_h

/*
 * Class: CharStack
 * ----------------
 * This class models a stack of character. The fundamental operations
 * are the same as those for the Stack<char> class.
 */
class CharStack{
public:
    /*
     * Constructor: CharStack
     * Usage: CharStack cstk;
     * ----------------------
     * Initializes a new empty stack that can conatin characters.
     */
    CharStack();

    /*
     * Destructor: ~CharStack
     * Usage: (usually implicit)
     * -------------------------
     * Frees any heap storage associated with this character stack.
     */

    ~CharStack();

    /*
     * Method: size
     * Usage: int nElems = cstk.size();
     * -------------------------------
     * Returns the number of characters in this stack.
     */
    int size();

    /*
     * Method: isEmpty
     * Usage: if(cstk.isEmpty()) . . .
     * -------------------------------
     * Returns true if this stack contains no characters.
     */
    bool isEmpty();

    /*
     * Method: clear
     * Usage: cstk.clear();
     * --------------------
     * Removes all characters from this stack.
     */
    void clear();

    /*
     * Method: push
     * Usage: cstk.push(ch);
     * ---------------------
     * Pushes the character ch onto this stack.
     */
    void push(char ch);

    /*
     * Method: pop
     * Usage: char ch = cstk.pop();
     * ----------------------------
     * Remove the top character from this stack and return it.
     */
    char pop();

    /*
     * Method: peak
     * Usage: char ch = cstk.peak();
     * -----------------------------
     * Returns the value of top character from this stack without
     * removing it. Raises an error if called on an empty stack.
     */
    char peak();

    /*
     * The private section of the class goes here.
     */

    /* Private section */

    /*
     * Implementation notes
     * ---------------------
     * In this version of CharStack, the  characters are stored in a dynamic
     * array that doubles in size whenever the stack runs out of space.
     */
private:
    /* Private constants */
    static const int INITIAL_CAPACITY = 10;
    /* Instance variables */

    char *array;        // Dynamic array of character.
    int capacity;       // Allocated size of that array
    int count;          // Current count of chars pushed

    /* Private function prototype (helper function)*/
    void expandCapacity();
};

#endif
