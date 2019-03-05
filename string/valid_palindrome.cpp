#include "./../lc.h"

bool solution(string s) {
    int length = s.length();
    int i = 0, j = length - 1;
    while(i < j) {
        while(!isalnum(s[i]) && i < j) i++;
        while(!isalnum(s[j]) && i < j) j--;
        
        if(tolower(s[i++]) == tolower(s[j--]))
            continue;
        else
            return false;
    }
    return true;
}

int main(int argc, char **argv) {
    bool res1 = solution("A man, a plan, a canal: Panama");
    bool res2 = solution("race a car");
    std::cout << "done.";
    return 0;
}