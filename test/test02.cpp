#include "./../lc.h"

vector<int> mergeSort(const vector<int> &nums, int start, int end, long long &cnt) {
    if(start > end) return {};
    if(start == end) return {nums[start]};
    int mid = (start + end) >> 1;
    vector<int> lvec = mergeSort(nums, start, mid, cnt);
    vector<int> rvec = mergeSort(nums, mid + 1, end, cnt);
    
    int lend = lvec.size() - 1;
    int rend = rvec.size() - 1;
    int len = end - start + 1;
    vector<int> result(len, 0);
    for(int i = len - 1; i >= 0; i--) {
        if(lend >= 0 && rend >= 0) {
            if(lvec[lend] > rvec[rend]) {
                cnt += rend + 1;
                result[i] = lvec[lend--];
            } else {
                result[i] = rvec[rend--];
            }
            continue;
        }
        if(lend >= 0)
            result[i] = lvec[lend--];
        if(rend >= 0)
            result[i] = rvec[rend--];
    }
    return result;
}

int main(int argc, char **argv) {
    long long cnt = 0;
    vector<int> nums = {1,2,3,4,5,6,7,0};
    vector<int> res = mergeSort(nums, 0, nums.size() - 1, cnt);

    std::cout << "done.";
    return 0;
}