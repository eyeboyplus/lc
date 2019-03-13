#include "./../lc.h"

vector<int> solution(string s, vector<string> &words) {
    map<string, int> words_map;
    vector<int> result;
    if(words.empty()) return result;

    for(string word : words)
        words_map[word] ++;
    int word_len = words[0].size();
    int word_cnt = words.size();
    int s_len = s.size();
    for(int i = 0; i <= s_len - word_cnt * word_len; i++) {
        int cnt = 0, idx = -1;
        map<string, int> map = words_map;
        for(int j = 0; j < word_cnt; j++) {
            string sub_s = s.substr(i + j * word_len, word_len);
            if(map.find(sub_s) == map.end())
                break;
            else {
                if(map[sub_s] > 0) {
                    if(cnt == 0)
                        idx = j;
                    cnt ++;
                    map[sub_s] -= 1;
                } else {
                    break;
                }
            }
        }
        if(cnt == word_cnt)
            result.push_back(idx);
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}