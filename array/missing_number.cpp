#include "./../lc.h"

// xor
int solution_1(vector<int> &nums) {
    int result = nums.size(), n = nums.size();
    for(int i = 0; i < n; ++i) {
        result ^= i;
        result ^= nums[i];
    }
    return result;
}

// sum
int solution_2(vector<int> &nums) {
    int n = nums.size();
    int sum = (0 + n) * (n + 1) / 2;
    for(int i = 0; i < n; ++i)
        sum -= nums[i];
    return sum;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}