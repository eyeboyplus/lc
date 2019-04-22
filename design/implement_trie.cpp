#include "./../lc.h"

struct TrieNode {
    char value;
    bool isWord;
    vector<TrieNode*> childern;

    TrieNode() : value(' '), isWord(false) {
        childern = vector<TrieNode*>(26, nullptr);
    }
    TrieNode(char c) : value(c), isWord(false) {
        childern = vector<TrieNode*>(26, nullptr);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *ptr = root;
        for(auto c : word) {
            if(ptr->childern[c - 'a'] == nullptr) {
                TrieNode *node = new TrieNode(c);
                ptr->childern[c - 'a'] = node;
            }
            ptr = ptr->childern[c - 'a'];
        }
        if(ptr != root)
            ptr->isWord = true;
    }

    bool search(string word) {
        TrieNode *ptr = root;
        for(auto c : word) {
            if(ptr->childern[c - 'a'] != nullptr)
                ptr = ptr->childern[c - 'a'];
            else
                return false;
        }

        return ptr->isWord;
    }

    bool startsWith(string prefix) {
        TrieNode *ptr = root;
        for(auto c : prefix) {
            if(ptr->childern[c - 'a'] != nullptr)
                ptr = ptr->childern[c - 'a'];
            else
                return false;
        }
        return true;
    }

private:
    TrieNode *root;
};

int main(int argc, char **argv) {
    Trie trie;

    trie.insert("apple");
    bool b = trie.search("apple");   // returns true
    b = trie.search("app");     // returns false
    b = trie.startsWith("app"); // returns true
    trie.insert("app");   
    b = trie.search("app");     // returns true
    std::cout << "done.";
    return 0;
}