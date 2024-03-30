
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
    // this is linked list not dynamic array
    // delete [] start;

    Node *cp = start, *ne;
    while(cp != NULL) {
        ne = cp->next;
        delete cp;
        cp = ne;
    }
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
    cursor = tmp;
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

    int cursorPosition = 0;
    Node *tmp = start;
    while(tmp != cursor) {
        cursorPosition ++;
        tmp = tmp->next;
    }
    return cursorPosition;
}
