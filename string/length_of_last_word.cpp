#include "./../lc.h"

int solution(string s) {
    int length = s.length();
    int end = length - 1;
    for(; end >= 0 && s[end] == ' '; end--);

    if(end = -1) return 0;
    int start = end;
    for(; start >= 0 && s[start] != ' '; --start);

    return end - start;    
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}