
#include <iostream>
#include "buffer.h"


                 /*
 * Constructor and Deconstructor
 * -----------------------------
 */
EditorBuffer::EditorBuffer() {
    start = cursor = new Node;
    // start->next = start->prev = NULL;
    start->prev = start->next = start;
}

EditorBuffer::~EditorBuffer() {
    // this is linked list not dynamic array
    // delete [] start;

    Node *startCp = start, *ne;
    do {
        ne = startCp->next;
        delete startCp;
        startCp = ne;
    } while(startCp != start);

}


/*
 * Implementation notes: moveCursor methods
 * ----------------------------------------
 */

void EditorBuffer::moveCursorForward() {
    if(cursor->next != start) {
        cursor = cursor->next;
    }
}

void EditorBuffer::moveCursorBackward() {
    if(cursor != start) {
        cursor = cursor->prev;
    }
}

void EditorBuffer::moveCursorToStart() {
    cursor = start;
}

void EditorBuffer::moveCursorToEnd() {
    cursor = start->prev;
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
    tmp->prev = cursor;
    if(cursor == cursor->next)  {
        // this list is empty
        cursor->prev = tmp;
    }
    cursor->next = tmp;
    cursor = tmp;
}

void EditorBuffer::deleteCharacter() {
    if(cursor->next != start) {
        Node *tmp = cursor->next;
        cursor->next = cursor->next->next;
        cursor->next->prev = cursor;
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
    while(tmp != start) {
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
