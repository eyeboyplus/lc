#include "./../lc.h"

struct TrieNode {
    char c;
    bool isWord;
    vector<TrieNode*> childern;

    TrieNode() : c(' '), isWord(false) {
        childern = vector<TrieNode*>(26, nullptr);
    }
    TrieNode(char c) : c(c), isWord(false) {
        childern = vector<TrieNode*>(26, nullptr);
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
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
        return search(word, 0, root);
    }

private:
    TrieNode *root;

    bool search(string word, int start, TrieNode *ptr) {
        int n = word.size();
        for(int i = start; i < n && ptr; i++) {
            char c = word[i];
            if(c == '.') {
                TrieNode *tmp = ptr;
                for(int j = 0; j < 26; j++) {
                    ptr = tmp->childern[j];
                    if(ptr && search(word, i + 1, ptr))
                        return true;
                }
            } else {
                ptr = ptr->childern[c - 'a'];
            }
        }
        return ptr && ptr->isWord;
    }
};

int main(int argc, char **argv) {
    WordDictionary wd;
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    bool b = wd.search("pad"); // false
    b = wd.search("bad"); // true
    b = wd.search(".ad"); // true
    b = wd.search("b.."); // true

    std::cout << "done.";
    return 0;
}