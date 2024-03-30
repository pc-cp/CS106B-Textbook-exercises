
#include <iostream>
#include "buffer.h"

/*
 * Constructor: EditorBuffer
 * Usage: EditorBuffer buffer;
 * ---------------------------
 * effectiveSize: count = 0;
 * currentCursor: cursorPosition = 0;
 */
EditorBuffer::EditorBuffer() {
    cursorPosition = 0;
    count = 0;
}

/*
 * Deconstructor: ~EditorBuffer
 * Usage: usually implicit;
 * ------------------------
 * free heap storage that allocated by this class.
 */
EditorBuffer::~EditorBuffer() {

}

/*
 * Method: moveCursorForward
 * Usage: buffer.moverCursorForward();
 * -----------------------------------
 * make the cursorPosition forward one character position.
 * if cursorPosition have been behind the last character, it take no effect.
 */
void EditorBuffer::moveCursorForward() {
    if(!after.isEmpty()) {
        before.push(after.pop());
        cursorPosition ++;
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
    if(!before.isEmpty()) {
        after.push(before.pop());
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
    while(!before.isEmpty()) {
        after.push(before.pop());
        cursorPosition--;
    }

}

/*
 * Method: moveCursorToEnd
 * Usage: buffer.moveCursorToEnd();
 * --------------------------------
 * Moves the cursor to the end of the buffer.
 */
void EditorBuffer::moveCursorToEnd() {
    while(!after.isEmpty()) {
        before.push(after.pop());
        cursorPosition++;
    }
}

/*
 * Method: insertCharacter
 * Usage: buffer.insertCharacter(ch);
 * ----------------------------------
 * Inserts the character ch at the current cursor position.
 *
 */
void EditorBuffer::insertCharacter(char ch) {
    before.push(ch);
    cursorPosition++;
    count++;
}

/*
 * Method: deleteCharacter
 * Usage: buffer.deleteCharacter()
 * -------------------------------
 *
 */
void EditorBuffer::deleteCharacter() {
    if(!after.isEmpty()) {
        after.pop();
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

    CharStack beforeCp = before, afterCp = after;

    while(!beforeCp.isEmpty()) {
        res = beforeCp.pop() + res;
    }

    while(!afterCp.isEmpty()) {
        res += afterCp.pop();
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
