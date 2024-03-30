
#include <iostream>
#include "buffer.h"
#include "charstack.h"



/*
 * Constructor and Deconstructor
 * -----------------------------
 * In this implementation, all dynamic allocation is managed by the
 * CharStack class, which means there is no work for EditorBuffer to do.
 */
EditorBuffer::EditorBuffer() {
}

EditorBuffer::~EditorBuffer() {

}


/*
 * Implementation notes: moveCursor methods
 * ----------------------------------------
 * The four moveCursor methods use push and pop to transfer
 * values between the two stack.
 */

void EditorBuffer::moveCursorForward() {
    if(!after.isEmpty()) {
        before.push(after.pop());
    }

}

void EditorBuffer::moveCursorBackward() {
    if(!before.isEmpty()) {
        after.push(before.pop());
    }
}

void EditorBuffer::moveCursorToStart() {
    while(!before.isEmpty()) {
        after.push(before.pop());
    }

}

void EditorBuffer::moveCursorToEnd() {
    while(!after.isEmpty()) {
        before.push(after.pop());
    }
}

/*
 * Implementation notes: character insertion and deletion
 * ------------------------------------------------------
 * Each of the functions that inserts or deletes character can do so
 * with a single push or pop operation.
 *
 */
void EditorBuffer::insertCharacter(char ch) {
    before.push(ch);
}

void EditorBuffer::deleteCharacter() {
    if(!after.isEmpty()) {
        after.pop();
    }
}

/*
 * Implementation notes: getText and getCursor
 * -------------------------------------------
 * The only difficult part of implementing these operators is making
 * sure that the state of the buffer is restored after copying the
 * character from the two stacks.
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

int EditorBuffer::getCursor() const {
    return before.size();
}
