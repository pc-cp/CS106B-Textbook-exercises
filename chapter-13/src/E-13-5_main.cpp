
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
#include <iomanip>
#include "buffer.h"

#include "simpio.h"
#include "strlib.h"

using namespace std;

/* Function prototypes */
void executeCommand(EditorBuffer &buffer, string line);
void displayBuffer(EditorBuffer &buffer);
void printHelpText();
void readLine(EditorBuffer &buffer);

int main() {

    EditorBuffer buffer;

    while(true) {
        string cmd = getLine("*");
        /*
         * the F, B, and D commands take a repetition count specified by a string of digits before the command letter.
         * so we make 17F to F17
         */
        if(isnumber(cmd[0]) && (cmd[cmd.size()-1] == 'F' || cmd[cmd.size()-1] == 'B' || cmd[cmd.size()-1] == 'D')) {
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

    int repetitions;
    switch (toupper(line[0])) {
    case 'I':
        for(int i = 1; i < line.size(); ++i) {
            buffer.insertCharacter(line[i]);
        }
        break;
    case 'D':
        repetitions = stringToInteger(line.substr(1));
        while(repetitions--) {
            buffer.deleteCharacter();
        }
        break;
    case 'F':
        repetitions = stringToInteger(line.substr(1));
        while(repetitions--) {
            buffer.moveCursorForward();
        }
        break;
    case 'B':
        repetitions = stringToInteger(line.substr(1));
        while(repetitions--) {
            buffer.moveCursorBackward();
        }
        break;
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
    case 'A':
        readLine(buffer); break;
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
    cout << buffer.getText();
}


/*
 * Function: printHelpText
 * Usage: printHelpText();
 * -----------------------
 * Displays a message showing the legal commands.
 */

void printHelpText() {
    cout << "Editor commands: " << endl;
    cout << " Iabc     Inserts the characters \"abc\" at the cursor position" << endl;
    cout << " (x)F     Moves the cursor forward one character, (commands take a repetition count specified by a string of digits before the command letter(x)." << endl;
    cout << " (x)B     Moves the cursor backward one character, (commands take a repetition count specified by a string of digits before the command letter(x)." << endl;
    cout << " (x)D     Deletes the character after the cursor, (commands take a repetition count specified by a string of digits before the command letter(x)" << endl;
    cout << " J        Jumps to the beginning of the buffer." << endl;
    cout << " E        Jumps to the end of the buffer" << endl;
    cout << " H        Prints this message" << endl;
    cout << " Q        Exits from the editor program" << endl;
    cout << " T        Print the contents of the buffer as a string." << endl;
    cout << " A        reads text on subsequent lines, ending when the user enters a line consisting of a single period." << endl;
}

/*
 * Function: readLine
 * Usage: readLine(buffer);
 * ------------------------
 * add an A command that reads text on subsequent lines,
 * ending when the user enters a line consisting of a single period.
 *
 * Notes: noskipws make ch is possible whithspace
 */
void readLine(EditorBuffer &buffer) {

    char ch;
    bool newLine = true;
    while(cin >> noskipws >> ch) {
        if(newLine && ch == '.') {
            cin >> ch;
            break;
        }
        newLine = false;
        buffer.insertCharacter(ch);
        if(ch == '\n') {
            newLine = true;
        }

    }
}
