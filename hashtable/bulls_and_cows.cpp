#include "./../lc.h"

string solution(string secret, string guess) {
    unordered_map<char, int> map;
    for(string::const_iterator it = secret.begin(); 
    it != secret.end(); it ++)
        map[*it] ++;
    int bulls = 0, cows = 0;
    int m = secret.size(), n = guess.size();
    for(int i = 0, j = 0; j < n; ++i, ++j) {
        if(i < m && secret[i] == guess[j]) {
            bulls ++;
            map[secret[i]] --;
        }
        if(map.find(guess[j]) != map.end() && map[guess[j]] > 0) {
            cows++;
            map[guess[j]] --;
        }
            
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}