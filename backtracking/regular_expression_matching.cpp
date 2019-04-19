#include "./../lc.h"

bool backtracking(const string &s, int sidx, const string &p, int pidx) {
    if(sidx == s.size() && pidx == p.size()) return true;

    if(pidx == p.size() - 1) {
        if(sidx == s.size())
            return false;
        
        if(sidx == s.size() - 1)
            return s[sidx] == p[pidx] || p[pidx] == '.';
    }

    // 此时
    if(p[pidx + 1] != '*') {
        if(sidx == s.size()) 
            return false;

        return (p[pidx] == s[sidx] || p[pidx] == '.') && backtracking(s, sidx + 1, p, pidx + 1);
    } else {
        // 不能确定重复元素的个数，只能遍历尝试
        while(sidx < s.size() && (s[sidx] == p[pidx] || p[pidx] == '.')) {
            if(backtracking(s, sidx, p, pidx + 2)) 
                return true;
            sidx ++;
        }
        return backtracking(s, sidx, p, pidx + 2);      // 并没有匹配，则再做一次
    }
}

bool solution(string s, string p) {
    if(p.empty()) return s.empty();

    if(p.length() == 1) {
        if(s.empty())
            return false;
        
        if(s.length() == 1)
            return p[0] == s[0] || p[0] == '.';
    }

    if(p[1] != '*') {      // the second character of pattern string is not *
        if(s.empty())
            return false;

        return (p[0] == s[0] || p[0] == '.') && solution(s.substr(1), p.substr(1));
    } else {              // the second character of pattern string is *
        // can not determine the number of duplicate charaters, we have to try all possibilities
        while(!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            if(solution(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        return solution(s, p.substr(2));
    }
}

int main(int argc, char **argv) {
    bool res1 = solution("aaa", "aa");
    bool res2 = solution("aa", "a*");
    bool res3 = solution("aab", "c*a*b");
    bool res4 = solution("bbabacccbcbbcaaab", "a*b*a*a*c*aa*c*bc*");
    std::cout << "done.";
    return 0;
}