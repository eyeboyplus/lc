#include "./../lc.h"

bool solution(string s, string t) {
    if(s.size() != t.size())
        return false;
    
    int m = s.size();
    unordered_map<char, char> smap;
    unordered_map<char, char> tmap;
    for(int i = 0; i < m; ++i) {
        if(smap.find(s[i]) == smap.end())
            smap[s[i]] = t[i];
        if(tmap.find(t[i]) == tmap.end())
            tmap[t[i]] = s[i];
        if(smap[s[i]] != t[i] || tmap[t[i]] != s[i])
            return false;
    }
    return true;
}

bool solution_1(string s, string t) {
    int m1[256] = {0}, m2[256] = {0}, n = s.size();
    for(int i = 0; i < n; i++) {
        if(m1[s[i]] != m2[t[i]]) return false;
        m1[s[i]] = i + 1;
        m1[t[i]] = i + 1;
    }
    return true;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}