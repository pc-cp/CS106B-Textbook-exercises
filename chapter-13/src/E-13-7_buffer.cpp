
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
    before = 0;
    after = capacity-1;
    copyBuffer = NULL;
    copyLength = 0;
}

/*
 * Deconstructor: ~EditorBuffer
 * Usage: usually implicit;
 * ------------------------
 * free heap storage that allocated by this class.
 */
EditorBuffer::~EditorBuffer() {
    delete [] array;
}

/*
 * Method: moveCursorForward
 * Usage: buffer.moverCursorForward();
 * -----------------------------------
 * make the cursorPosition forward one character position.
 * if cursorPosition have been behind the last character, it take no effect.
 */
void EditorBuffer::moveCursorForward() {
    if(after != capacity-1) {
        array[before] = array[after+1];
        before++;
        after++;
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
    if(before != 0) {
        array[after] = array[before-1];
        before--;
        after--;

    }
}

/*
 * Method: moveCursorToStart
 * Usage: buffer.moveCursorToStart();
 * ----------------------------------
 * Jumps to the beginning of the buffer.
 */
void EditorBuffer::moveCursorToStart() {
    while(before != 0) {
        array[after] = array[before-1];
        after--;
        before--;
    }
}

/*
 * Method: moveCursorToEnd
 * Usage: buffer.moveCursorToEnd();
 * --------------------------------
 * Moves the cursor to the end of the buffer.
 */
void EditorBuffer::moveCursorToEnd() {
    while(after != capacity-1) {
        array[before] = array[after+1];
        before++;
        after++;
    }
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
    if(before == after) {
        expandCapacity();
    }

    array[before] = ch;
    before++;

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
    if(after != capacity-1) {
        after++;
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
    for(int i = 0; i < before; ++i) {
        res += array[i];
    }

    for(int i = after+1; i < capacity; ++i) {
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
    return before;
}

/*
 * Method: copy
 * Usage: buffer.copy(count);
 * --------------------------
 * stores a copy of the next count characters somewhere in the internal structure for the buffer
 */
void EditorBuffer::copy(int count) {

    if(copyLength != 0) {
        delete [] copyBuffer;
    }

    copyLength = ((count <= (capacity - 1 - after)) ? count : (capacity - 1 - after));

    copyBuffer = new char [copyLength];

    for(int i = 0; i < copyLength; ++i) {
        copyBuffer[i] = array[after + i + 1];
    }
}

/*
 * Method: paste
 * Usage: buffer.paste();
 * --------------------------
 * inserts those saved characters back into the buffer at the current cursor position
 */

void EditorBuffer::paste() {
    for(int i = 0; i < copyLength; ++i) {
        insertCharacter(copyBuffer[i]);
    }
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

    int newCapacity = 2 * capacity;
    this->array = new char[newCapacity];

    for(int i = 0; i < before; ++i) {
        this->array[i] = oldArray[i];
    }

    int numBetweenAfterAndCapacity = capacity - 1 - after;
    for(int i = 0; i < numBetweenAfterAndCapacity; ++i) {
        this->array[newCapacity-1-i] = oldArray[capacity-1-i];
    }
    capacity = newCapacity;
    after = capacity - 1 - numBetweenAfterAndCapacity;

    delete [] oldArray;
}
