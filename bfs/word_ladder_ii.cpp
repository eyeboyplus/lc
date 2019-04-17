#include "./../lc.h"

// Timeout
vector<vector<string>> solution(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> ret;
    unordered_set<string> dict(wordList.begin(), wordList.end());
    queue<vector<string>> todo;
    todo.push({beginWord});

    int min = INT_MAX;

    while(!todo.empty()) {
        vector<string> paths = todo.front();
        todo.pop();

        string word = paths.back();
        if(word == endWord) {
            if(paths.size() <= min) {
                min = paths.size();
                ret.push_back(paths);
            }
        }

        dict.erase(word);
        for(int i = 0; i < word.size(); i++) {
            char c = word[i];
            for(int j = 0; j < 26; j++) {
                word[i] = 'a' + j;
                if(dict.find(word) != dict.end()) {
                    vector<string> newPaths = paths;
                    newPaths.push_back(word);
                    todo.push(newPaths);
                }
            }
            word[i] = c;
        }
    }
    return ret;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}