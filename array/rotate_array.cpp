#include "./../lc.h"

void reverse(vector<int> &nums, int start, int end) {
    while(start < end) {
        swap(nums[start++], nums[end--]);
    }
}

void solution(vector<int> &nums, int k) {
    k %= nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}