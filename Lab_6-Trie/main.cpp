#include <iostream>
#include "string"
#define NUMBER_OF_LETTERS 26
using namespace std;

class Trie {
public:
    class TrieNode {
    public:
        TrieNode* children[NUMBER_OF_LETTERS];
        string polishEquivalent;
        bool isWord;

        TrieNode() {
            polishEquivalent = "-";
            isWord = false;
            for (int i = 0; i < NUMBER_OF_LETTERS; ++i)
                children[i] = nullptr;
        
}

    
};
public:
    TrieNode* children[NUMBER_OF_LETTERS];
    Trie() {
        for (int i = 0; i < NUMBER_OF_LETTERS; ++i) {
            children[i] = new TrieNode();
        
}
    
}
    void insert(string englishWord, string polishEquivalent) {
        TrieNode* temp = children[0];

        for (int i = 0; i < englishWord.length(); ++i) {
            int index = englishWord[i] - 'a';
            if (temp != nullptr) {
                if (temp->children[index] == nullptr) {
                    temp->children[index] = new TrieNode();
                
}
                temp = temp->children[index];
            
}
        
}
        temp->polishEquivalent = polishEquivalent;
        temp->isWord = true;
    
}

    string search(string word) {
        TrieNode* temp = children[0];

        for (int i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';
            if (temp->children[index] == nullptr)
                return "-";
            else
                temp = temp->children[index];
        
}
        return temp->polishEquivalent;
    
}
};

int main() {
    Trie newTrie = Trie();
    string command;
    string polishWord, englishWord;

    while (cin>>command){
        if (command == "+") {
            cin >> englishWord >> polishWord;
            newTrie.insert(englishWord, polishWord);
        
} else if (command == "?") {
            cin >> englishWord;
            cout << newTrie.search(englishWord) << endl;
        
}
    
}
    return 0;
}