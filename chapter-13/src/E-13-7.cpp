
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
#include "strlib.h"

using namespace std;

/* Function prototypes */
void executeCommand(EditorBuffer &buffer, string line);
void displayBuffer(EditorBuffer &buffer);
void printHelpText();

int main() {
    EditorBuffer buffer;

    while(true) {
        string cmd = getLine("*");
        if(isnumber(cmd[0]) && cmd[cmd.size()-1] == 'C') {
            cmd = cmd.substr(cmd.size()-1) + cmd.substr(0, cmd.size()-1);
        }
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
    int count;

    switch (toupper(line[0])) {

        case 'I':
            for(int i = 1; i < line.size(); ++i) {
                buffer.insertCharacter(line[i]);
            }
            displayBuffer(buffer);
            break;
        case 'D':
            buffer.deleteCharacter(); displayBuffer(buffer); break;
        case 'F':
            buffer.moveCursorForward(); displayBuffer(buffer); break;
        case 'B':
            buffer.moveCursorBackward(); displayBuffer(buffer); break;
        case 'J':
            buffer.moveCursorToStart(); displayBuffer(buffer); break;
        case 'E':
            buffer.moveCursorToEnd(); displayBuffer(buffer); break;
        case 'H':
            printHelpText(); break;
        case 'Q':
            exit(0);
            break;
        case 'C':
            count = stringToInteger(line.substr(1));
            buffer.copy(count);
            displayBuffer(buffer);
            break;
        case 'P':
            buffer.paste();
            displayBuffer(buffer);
            break;
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
    string str = buffer.getText();
    for(int i = 0; i < str.size(); ++i) {
        cout << " " << str[i];
    }
    cout << endl;
    cout << string(2 * buffer.getCursor(), ' ') << "^" << endl;
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
    cout << "(7)C   Stores a copy of the next (7)count characters." << endl;
    cout << " P     Inserts those saved characters back into the buffer at the current cursor position." << endl;
}
