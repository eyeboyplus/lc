#include "./../lc.h"

bool solution(string s, string p) {
    int sIdx = 0, pIdx = 0, starIdx = -1, matchIdx = 0;
    int sLen = s.size(), pLen = p.size();
    while(sIdx < sLen) {
        if(pIdx < pLen && (p[pIdx] == s[sIdx] || p[pIdx] == '?')) {
            sIdx ++;
            pIdx ++;
        } else if(pIdx < pLen && p[pIdx] == '*') {
            starIdx = pIdx;
            matchIdx = sIdx;
            pIdx ++;
        } else if(starIdx != -1) {
            pIdx = starIdx + 1;
            matchIdx ++;
            sIdx = matchIdx;
        } else {
            return false;
        }
    }
    while(pIdx < pLen && p[pIdx] == '*')
        pIdx ++;
        
    return pIdx == pLen;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}