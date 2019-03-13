#include "./../lc.h"

bool solution(string pattern, string str) {
    int n = pattern.size();
    istringstream in(str);
    map<char, int> p2w;
    map<string, int> w2p;

    int i = 0;
    for(string word; in >> word; ++i) {
        if(i == n || p2w[pattern[i]] != w2p[word])
            return false;
        p2w[pattern[i]] = i + 1;
        w2p[word] = i + 1;
    }
    return i == n;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}