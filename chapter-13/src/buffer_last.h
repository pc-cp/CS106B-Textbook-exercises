
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

    /*
     * Method: copy
     * Usage: buffer.copy(count);
     * --------------------------
     * stores a copy of the next count characters somewhere in the internal structure for the buffer
     */
    void copy(int count);

    /*
     * Method: paste
     * Usage: buffer.paste();
     * ----------------------
     * inserts those saved characters back into the buffer at the current cursor position
     */
    void paste();

    /*
     * Method: cut
     * Usage: buffer.cut(count);
     * -------------------------
     * copies the text from the buffer and then deletes it.
     */
    void cut(int count);

    /*
     * Method: search
     * Usage: buffer.search(str);
     * --------------------------
     * start searching from the current cursor position,
     * looking for the next occurrence of the string str.
     */
    bool search(std::string str);

    /*
     * Method: replace
     * Usage: buffer.replace(src, des);
     * --------------------------------
     * replaces the next occurrence of one string (src) with another (des).
     */
    bool replace(std::string str, std::string des);
    /* The private section of the class goes here.*/

private:
    static const int INITIAL_CAPACITY = 10;
    char *array;        // Dynamic array of character
    int capacity;       // Allocated size of that array
    int before, after;

    char *copyBuffer;
    int copyLength;

    void expandCapacity();

    EditorBuffer(const EditorBuffer &src) { }

    EditorBuffer & operator= (const EditorBuffer &src) {return *this;}
    int searchKMP(std::string src, std::string des);
};

/* The implementation of the class goes here.*/

#endif // _buffer_h
