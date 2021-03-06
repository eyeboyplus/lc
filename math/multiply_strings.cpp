#include "./../lc.h"

string solution(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');
    int n1 = num1.size(), n2 = num2.size();
    for(int i = n1 - 1; i >= 0; --i) {
        int carray = 0;
        for(int j = n2 - 1; j >=0; --j) {
            int tmp = sum[i + j - 1] - '0' + (num1[i] - '0') * (num2[j] - '0') + carray;
            sum[i + j + 1] = tmp % 10 + '0';
            carray = tmp / 10;
        }
        sum[i] += carray;
    }
    size_t startpos = sum.find_first_not_of("0");
    if(string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}