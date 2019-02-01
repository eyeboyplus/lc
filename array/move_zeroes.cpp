#include "./../lc.h"

void solution(vector<int> &nums) {
    int n = nums.size(), index = 0;
    for(int i = 0; i < n; ++i) {
        if(nums[i] == 0)
            continue;
        nums[index++] = nums[i];
    }
    for(int i = index; i < n ++i)
        nums[i] = 0;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}