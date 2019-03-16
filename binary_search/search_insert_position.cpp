#include "./../lc.h"

int solution(vector<int> &nums, int target) {
    int l = 0, h = nums.size() - 1;
    // the desired index is between [l, h + 1]
    while(l <= h) {
        int mid = (l + h) / 2;
        if(target == nums[mid])
            return mid;
        else if(target > nums[mid])
            l = mid + 1;
        else 
            h = mid - 1;
    }
    // at this point, l > h, that is l >= h + 1
    // l <= h + 1,so we known l = h + 1
    return l;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}