#include "./../lc.h"

int solution(string version1, string version2) {
    int len1 = version1.length(), len2 = version2.length();
    int num1 = 0, num2 = 0;
    for(int i = 0, j = 0; i < len1 || j < len2;) {
        while(i < len1 && version1[i] != '.') {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }
        while(j < len2 && version2[j] != '.') {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;  
        }
        if(num1 > num2) return 1;
        if(num1 < num2) return -1;

        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }
    return 0;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}