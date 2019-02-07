#include "./../lc.h"

void solution(vector<int> &nums) {
    int zero = 0, two = nums.size() - 1;
    for(int i = 0; i <= two; ++i) {
        while(nums[i] == 2 && i < two)
            swap(nums[i], nums[two--]);
        while(nums[i] == 0 && i > zero)
            swap(nums[i], nums[zero++]);
    }
}

int main(int argc, char **argv) {
    vector<int> nums = {2,0,2,1,1,0};
    solution(nums);
    std::cout << "done.";
    return 0;
}