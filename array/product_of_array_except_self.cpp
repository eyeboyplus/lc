#include "./../lc.h"

vector<int> solution_1(vector<int> &nums) {
    int n = nums.size();
    vector<int> leftAcc(n, 1);
    vector<int> rightAcc(n, 1);
    for(int i = 1; i < n; i++) {
        leftAcc[i] = leftAcc[i - 1] * nums[i - 1];
        rightAcc[i] = rightAcc[i - 1] * nums[n - i];
    }
    vector<int> result(n);
    for(int i = 0; i < n; ++i)
        result[i] = leftAcc[i] * rightAcc[n - 1 - i];
    return result;
}

// 优化版
vector<int> solution_2(vector<int> &nums) {
    int n = nums.size(), fromBegin = 1, fromLast = 1;
    vector<int> result(n, 1);

    for(int i = 0; i < n; ++i) {
        result[i] *= fromBegin;
        fromBegin *= nums[i];
        result[n - 1 - i] *= fromLast;
        fromLast *= nums[n - 1 - i];
    }
    
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}