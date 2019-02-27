#include "./../lc.h"

string solution(int n, int k) {
    vector<int> numbers;
    vector<int> factorial (n, 1);
    for(int i = 1; i < n; i++)
        factorial[i] = factorial[i - 1] * i;

    for(int i = 1; i <= n; i++)
        numbers.push_back(i);
    k--;
    string result;
    for(int i = 1; i <= n; i++) {
        int idx = k / factorial[n - i];
        result.push_back(numbers[idx] + '0');
        numbers.erase(numbers.begin() + idx, numbers.begin() + idx + 1);
        k -= idx * factorial[n - i];
    }

    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}