#include "./../lc.h"

string solution(string s) {
    int length = s.length();
    string result;
    for(int i = length - 1; i >=0;) {
        int end = -1;
        while(i >= 0 && s[i] == ' ') i--;
        if(i < 0) break;
        end = i;
        
        while(i >=0 && s[i] != ' ') i--;
        if(i < 0) {
            if(end > 0) {
                result += s.substr(0, end + 1) + " ";
                break;
            }
        }
        result += s.substr(i + 1, end - i) + " ";
    }
    if(result.empty()) return result;
    return result.substr(0, result.length() - 1);
}

int main(int argc, char **argv) {
    string res1 = solution("the sky is blue");
    string res2 = solution("  hello world!  ");
    string res3 = solution("a good   example");
    std::cout << "done.";
    return 0;
}