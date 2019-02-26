#include "./../lc.h"

vector<int> solution(vector<int> &digits) {
    int n = digits.size();
    for(int i = n - 1; i >= 0; --i) {
        if(digits[i] < 9) {
            digits[i] ++;
            return digits;
        } else {
            digits[i] = 0;
        }
    }
    vector<int> result(n + 1, 0);
    result[0] = 1;
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}