#include "./../lc.h"

int solution(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    queue<string> todo;
    todo.push(beginWord);
    int ladder = 1;
    while(!todo.empty()) {
        int size = todo.size();
        for(int idx = 0; idx < size; idx++) {
            string word = todo.front();
            todo.pop();
            if(word == endWord) 
                return ladder;

            dict.erase(word);
            int n = word.size();
            for(int i = 0; i < n; i++) {
                int c = word[i];
                for(int j = 0; j < 26; j++) {
                    word[i] = 'a' + j;
                    if(dict.find(word) != dict.end())
                        todo.push(word);
                }
                word[i] = c;
            }
        }
        ladder++;
    }
    return 0;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}