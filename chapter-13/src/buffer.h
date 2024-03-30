
/*
 * File: buffer.h
 * --------------
 * This file defines the interface for the EditorBuffer class.
 *
 */

#ifndef _buffer_h
#define _buffer_h

/*
 * Class: EditorBuffer
 * -------------------
 * This class represents an editor buffer, which maintains an ordered
 * sequence of character along with an insertion point called the cursor.
 */

class EditorBuffer {
public:
    /*
     * Constructor: EditorBuffer
     * Usage: EditorBuffer buffer;
     * ---------------------------
     * Creates an empty editor buffer.
     */

    EditorBuffer();


    /*
     * Destructor: ~EditorBuffer
     * Usage: (usually implicit)
     * -------------------------
     * Frees any heap storage associated with this buffer.
     */

    ~EditorBuffer();

    /*
     * Method: moverCursorForward, moverCursorBackward
     * Usage: buffer.moveCursorForward();
     *        buffer.moveCursorBackward();
     * -----------------------------------
     * These function move the cursor forward or backward one character,
     * respectively. If the command would shift the cursor beyond either
     * end of the buffer, this method has no effect.
     */

    void moveCursorForward();
    void moveCursorBackward();

    /*
     * Methods: moveCursorToStart, moveCursorToEnd
     * Usage: buffer.moverCursorToStart, buffer.moveCursorToEnd
     * --------------------------------------------------------
     * These functions move the cursor to the start or the end of this buffer.
     */
    void moveCursorToStart();
    void moveCursorToEnd();

    /*
     * Method: insertCharacter
     * Usage: buffer.insertCharacter(ch);
     * ----------------------------------
     * Inserts the character ch into this buffer at the cursor position,
     * leaving the cursor after the inserted character.
     */
    void insertCharacter(char ch);

    /*
     * Method: deleteCharacter
     * Usage: buffer.deleteCharacter();
     * --------------------------------
     * Deletes the character immediately after the cursor, if any.
     */

    void deleteCharacter();

    /*
     * Method: getText
     * Usage: buffer.getText();
     * ------------------------
     * Returns the contents of the buffer as a string.
     */
    std::string getText() const;

    /*
     * Method: getCursor;
     * Usage: buffer.getCursor();
     * --------------------------
     * Return the index of the cursor.
     */
    int getCursor() const;

    /* The private section of the class goes here.*/



};

/* The implementation of the class goes here.*/

#endif // _buffer_h
