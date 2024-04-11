

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct BSTNode {
    char key;

    BSTNode *left;
    BSTNode *right;
};
void makeTranslationTables(BSTNode *&root, map<char, string>& translationTables);
void insertNode(BSTNode *&root, const char letter, const string &morse, int pos);
void deleteTree(BSTNode *root);
char getMorseCodeLetter(BSTNode *&root, const string& code);
char getMorseCodeLetterRec(BSTNode *&root, const string& code, int pos);
int main() {
    map<char, string> charToMorse;
    charToMorse['A'] = ".-";
    charToMorse['B'] = "-...";
    charToMorse['C'] = "-.-.";
    charToMorse['D'] = "-..";
    charToMorse['E'] = ".";
    charToMorse['F'] = "..-.";
    charToMorse['G'] = "--.";
    charToMorse['H'] = "....";
    charToMorse['I'] = "..";
    charToMorse['J'] = ".---";
    charToMorse['K'] = "-.-";
    charToMorse['L'] = ".-..";
    charToMorse['M'] = "--";
    charToMorse['N'] = "-.";
    charToMorse['O'] = "---";
    charToMorse['P'] = ".--.";
    charToMorse['Q'] = "--.-";
    charToMorse['R'] = ".-.";
    charToMorse['S'] = "...";
    charToMorse['T'] = "-";
    charToMorse['U'] = "..-";
    charToMorse['V'] = "...-";
    charToMorse['W'] = ".--";
    charToMorse['X'] = "-..-";
    charToMorse['Y'] = "-.--";
    charToMorse['Z'] = "--..";
    BSTNode *root = nullptr;
    makeTranslationTables(root, charToMorse);

    for(auto keyValue: charToMorse) {
        cout << keyValue.second << " ---> " << getMorseCodeLetter(root, keyValue.second) << endl;
    }
    return 0;
}

char getMorseCodeLetter(BSTNode *&root, const string& code) {
    return getMorseCodeLetterRec(root, code, 0);
}

char getMorseCodeLetterRec(BSTNode *&root, const string& code, int pos) {
    if(pos == code.size()) {
        return root->key;
    }
    else {
        if(code[pos] == '.') {
            return getMorseCodeLetterRec(root->left, code, pos+1);
        }
        else {
            return getMorseCodeLetterRec(root->right, code, pos+1);
        }
    }
}

void makeTranslationTables(BSTNode *&root, map<char, string>& translationTables) {
    for(auto keyValue: translationTables) {
        insertNode(root, keyValue.first, keyValue.second, 0);
    }
}

void insertNode(BSTNode *&root, const char letter, const string &morse, int pos){
    if(root == nullptr) {
        root = new BSTNode;
        root->left = root->right = nullptr;
    }
    if(pos == morse.size()) {
        root->key = letter;
        return ;
    }
    else {
        if(morse[pos] == '.') {
            insertNode(root->left, letter, morse, pos+1);
        }
        if(morse[pos] == '-') {
            insertNode(root->right, letter, morse, pos+1);
        }
    }
}

void deleteTree(BSTNode *root) {
    if(root == nullptr) {
        return ;
    }
    else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

