
#include <iostream>
#include "buffer.h"


/*
 * Constructor and Deconstructor
 * -----------------------------
 */
EditorBuffer::EditorBuffer() {
    start = new Node;
    start->next = NULL;

    cursor = start;
}

EditorBuffer::~EditorBuffer() {
    delete [] start;
}


/*
 * Implementation notes: moveCursor methods
 * ----------------------------------------
 */

void EditorBuffer::moveCursorForward() {
    if(cursor->next) {
        cursor = cursor->next;
    }
}

void EditorBuffer::moveCursorBackward() {
    if(cursor != start) {
        Node *oldCursor = cursor;

        cursor = start;
        while(cursor->next != oldCursor) {
            cursor = cursor->next;
        }
    }
}

void EditorBuffer::moveCursorToStart() {
    cursor = start;
}

void EditorBuffer::moveCursorToEnd() {
    while(cursor->next) {
        cursor = cursor->next;
    }
}

/*
 * Implementation notes: character insertion and deletion
 * ------------------------------------------------------
 *
 */
void EditorBuffer::insertCharacter(char ch) {

    Node *tmp = new Node;
    tmp->value = ch;
    tmp->next = cursor->next;
    cursor->next = tmp;
    cursor = cursor->next;
}

void EditorBuffer::deleteCharacter() {
    if(cursor->next) {
        Node *tmp = cursor->next;
        cursor->next = cursor->next->next;
        delete tmp;
    }
}

/*
 * Implementation notes: getText and getCursor
 * -------------------------------------------
 */
std::string EditorBuffer::getText() const {
    std::string res = "";

    Node *tmp = start->next;
    while(tmp) {
        res += tmp->value;
        tmp = tmp->next;
    }

    return res;
}

int EditorBuffer::getCursor() const {
    Node *tmp = start->next;
    int cursorPosition = 0;
    while(tmp != cursor->next) {
        cursorPosition ++;
        tmp = tmp->next;
    }
    return cursorPosition;
}
