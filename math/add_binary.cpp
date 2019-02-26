#include "./../lc.h"

string solution(string a, string b) {
    string result;
    int c = 0, i = a.size() - 1, j = b.size() - 1;
    while(i >= 0 || j >= 0 || c == 1) { // a未遍历完 or b未遍历完 or 仍有进位
        c += i >= 0 ? a[i--] - '0' : 0;
        c += j >= 0 ? b[j--] - '0' : 0;
        result = char(c % 2 + '0') + result;
        c /= 2;
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}