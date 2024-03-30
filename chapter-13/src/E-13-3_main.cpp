
/*
 * File: SimpleTextEditor.cpp
 * --------------------------
 * This program implements a single command-driven text editor, which is
 * used to test the EditorBuffer class.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include "buffer.h"

#include "simpio.h"

using namespace std;

/* Function prototypes */
void executeCommand(EditorBuffer &buffer, string line);
void displayBuffer(EditorBuffer &buffer);
void printHelpText();

int main() {
    EditorBuffer buffer;

    while(true) {
        string cmd = getLine("*");
        if(cmd != "") executeCommand(buffer, cmd);
    }

    return 0;
}

/*
 * Function: executeCommand
 * Usage: executeCommand(buffer, cmd);
 * -----------------------------------
 * Executes the command specified by line on the editor buffer.
 */
void executeCommand(EditorBuffer &buffer, string line) {
    switch (toupper(line[0])) {
    case 'I':
        for(int i = 1; i < line.size(); ++i) {
            buffer.insertCharacter(line[i]);
        }
        break;
    case 'D':
        buffer.deleteCharacter(); break;
    case 'F':
        buffer.moveCursorForward(); break;
    case 'B':
        buffer.moveCursorBackward(); break;
    case 'J':
        buffer.moveCursorToStart(); break;
    case 'E':
        buffer.moveCursorToEnd(); break;
    case 'H':
        printHelpText(); break;
    case 'Q':
        exit(0);
        break;
    case 'T':
        displayBuffer(buffer); break;
    default:
        cout << "Illegal command" << endl; break;
    }
}

/*
 * Funciton: displayBuffer
 * Usage: displayBuffer(buffer);
 * -----------------------------
 * Displays the state of the buffer including the position of the cursor.
 */
void displayBuffer(EditorBuffer &buffer) {

    cout << buffer.getText() << endl;


    // string str = buffer.getText();
    // for(int i = 0; i < str.size(); ++i) {
    //     cout << " " << str[i];
    // }
    // cout << endl;
    // cout << string(2 * buffer.getCursor(), ' ') << "^" << endl;
}


/*
 * Function: printHelpText
 * Usage: printHelpText();
 * -----------------------
 * Displays a message showing the legal commands.
 */

void printHelpText() {
    cout << "Editor commands: " << endl;
    cout << " Iabc  Inserts the characters abc at the cursor position" << endl;
    cout << " F     Moves the cursor forward one character." << endl;
    cout << " B     Moves the cursor backward one character." << endl;
    cout << " D     Deletes the character after the cursor" << endl;
    cout << " J     Jumps to the beginning of the buffer." << endl;
    cout << " E     Jumps to the end of the buffer" << endl;
    cout << " H     Prints this message" << endl;
    cout << " Q     Exits from the editor program" << endl;
}
