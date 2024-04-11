
#include <iostream>
#include <fstream>
using namespace std;

const int BRANCHES = 26;
struct trie {
    bool flag;
    trie* link[BRANCHES];
};

void makeTrie(trie* &root, ifstream &infile);
void insertWordInTrie(trie* &root, const string &word);
void insertWordInTrieRec(trie* &root, const string &word, int pos);
bool findWord(const trie* root, const string &word);
bool findWordRec(const trie* root, const string &word, int pos);
int main() {
    ifstream infile;
    infile.open("./res/EnglishWords.txt");

    if(infile.fail()) {
        cout << "open failed." << endl;
        return 0;
    }

    trie *root = nullptr;
    makeTrie(root, infile);

    cout << findWord(root, "a") << endl;
    cout << findWord(root, "aa") << endl;
    cout << findWord(root, "aac") << endl;
    cout << findWord(root, "outs") << endl;
    cout << findWord(root, "outss") << endl;
    return 0;
}


void makeTrie(trie*& root, ifstream &infile) {
    string word;
    while(getline(infile, word)) {
        insertWordInTrie(root, word);
    }
    infile.close();
}

void insertWordInTrie(trie* &root, const string &word) {
    if(word.size() == 0) {
        return ;
    }
    insertWordInTrieRec(root, word, 0);
}

void insertWordInTrieRec(trie* &root, const string &word, int pos) {
    if(root == nullptr) {
        root = new trie;

        root->flag = false;
        for(int i = 0; i < BRANCHES; ++i) {
            root->link[i] = nullptr;
        }

    }
    if(pos == word.size()) {
        root->flag = true;
        return ;
    }

    int u = tolower(word[pos]) - 'a';
    insertWordInTrieRec(root->link[u], word, pos+1);
}


bool findWord(const trie* root, const string &word) {
    return findWordRec(root, word, 0);
}
bool findWordRec(const trie* root, const string &word, int pos) {
    if(root == nullptr) return false;

    if(pos == word.size()) {
        return root->flag;
    }

    int u = tolower(word[pos]) - 'a';
    return findWordRec(root->link[u], word, pos+1);
}
