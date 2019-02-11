#include "./../lc.h"

int solution(vector<int> nums) {
    int result = INT_MIN;
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        sum = max(sum + nums[i], nums[i]);
        result = max(sum, result);
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}