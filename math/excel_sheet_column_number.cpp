#include "./../lc.h"

int solution(string s) {
    int result = 0;
    int n = s.size();
    for(int i = 0; i < n; ++i)
        result = result * 26 + (s[i] - 'A' + 1);
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}