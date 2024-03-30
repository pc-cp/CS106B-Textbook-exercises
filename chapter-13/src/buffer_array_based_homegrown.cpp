
#include <iostream>
#include "buffer.h"

/*
 * Constructor: EditorBuffer
 * Usage: EditorBuffer buffer;
 * ---------------------------
 * make the buffer have ten char capacity, and
 * make the array point this heap storage,
 * effectiveSize: count = 0;
 * currentCursor: cursorPosition = 0;
 * buffer's capacity: capacity = CAPACITY_BUFFER;
 */
EditorBuffer::EditorBuffer() {
    capacity = INITIAL_CAPACITY;
    array = new char[capacity];
    count = 0;
    cursorPosition = 0;
}

/*
 * Deconstructor: ~EditorBuffer
 * Usage: usually implicit;
 * ------------------------
 * free heap storage that allocated by this class.
 */
EditorBuffer::~EditorBuffer() {
    delete [] array;
    array = NULL;
}

/*
 * Method: moveCursorForward
 * Usage: buffer.moverCursorForward();
 * -----------------------------------
 * make the cursorPosition forward one character position.
 * if cursorPosition have been behind the last character, it take no effect.
 */
void EditorBuffer::moveCursorForward() {
    if(cursorPosition != count) {
        cursorPosition++;
    }
}

/*
 * Method: moveCursorBackward
 * Usage: buffer.moveCursorBackward();
 * -----------------------------------
 * make the cursorPosition backward one character position.
 * if cursorPosition have been front the first character, it take no effect.
 */
void EditorBuffer::moveCursorBackward() {
    if(cursorPosition != 0) {
        cursorPosition--;
    }
}

/*
 * Method: moveCursorToStart
 * Usage: buffer.moveCursorToStart();
 * ----------------------------------
 * Jumps to the beginning of the buffer.
 */
void EditorBuffer::moveCursorToStart() {
    cursorPosition = 0;
}

/*
 * Method: moveCursorToEnd
 * Usage: buffer.moveCursorToEnd();
 * --------------------------------
 * Moves the cursor to the end of the buffer.
 */
void EditorBuffer::moveCursorToEnd() {
    cursorPosition = count;
}

/*
 * Method: insertCharacter
 * Usage: buffer.insertCharacter(ch);
 * ----------------------------------
 * Inserts the character ch at the current cursor position.
 * if buffer is filled, we should expand capacity of the buffer.
 *
 * if we have unused storage, we should make the characters those behind cursorPosition forward one character.
 */
void EditorBuffer::insertCharacter(char ch) {
    if(count == capacity) {
        expandCapacity();
    }
    /*
                0 1 2 3 4 5
                   ^
                0 1   2 3 4 5
    */
    for(int i = count; i > cursorPosition; i--) {
        array[i] = array[i-1];
    }


    array[cursorPosition] = ch;
    cursorPosition++;
    count++;        // if this statement lose will generate bug.
}

/*
 * Method: deleteCharacter
 * Usage: buffer.deleteCharacter()
 * -------------------------------
 * Deletes the character just after the current cursor position.
 *
 * if cursorPosition is behind the last character, we do nothing.
 * else
 *     make those character behind the cursorPosition backward one character.
 *                              0 1 2 3 4 5
                                   ^
                                0 1 3 4 5
                                   ^
 */
void EditorBuffer::deleteCharacter() {
    if(cursorPosition != count) {
        for(int i = cursorPosition+1; i < count; ++i) {
            array[i-1] = array[i];
        }
        count--;
    }

}

/*
 * Method: getText
 * Usage: string str = buffer.getText();
 * -------------------------------------
 * include character between [0, count).
 */
std::string EditorBuffer::getText() const {
    std::string res = "";
    for(int i = 0; i < count; ++i) {
        res += array[i];
    }
    return res;
}

/*
 * Method: getCursor
 * Usage: int cursorPosition = buffer.getCursor();
 * -----------------------------------------------
 * just return the instance variable: cursorPosition.
 */
int EditorBuffer::getCursor() const {
    return cursorPosition;
}

/*
 * Method: expandCapacity
 * Usage: private method
 * ---------------------
 * if current buffer is filled, but we want insert character in it.
 * we should expand capacity (capacity *= 2) of the buffer first and insert it.
 */
void EditorBuffer::expandCapacity() {
    char *oldArray = this->array;

    capacity *= 2;
    this->array = new char[capacity];
    for(int i = 0; i < count; ++i) {
        this->array[i] = oldArray[i];
    }
    delete [] oldArray;
}
