#include "./../lc.h"

vector<vector<int>> solution(vector<int> &nums) {
    vector<vector<int>> result;
    size_t size = nums.size();
    if (size < 3) return result;
    for (size_t i = 0; i < size; ++i) {
        if ( i > 0 && nums[i] == nums[i - 1]) continue;
        size_t j = i + 1, k = size - 1;        // j第二个数下标，k为第三个数下标
        while (j < k) {
            int val = nums[i] + nums[j] + nums[k];
            if (val < 0) {
                while ((++j) < k && nums[j] == nums[j - 1]);
            } else if ( val > 0) {
                while((--k) > j && nums[k] == nums[k + 1]);
            } else {
                vector<int> vec = {nums[i], nums[j], nums[k]};
                result.push_back(vec);
                while((++j) < k && nums[j] == nums[j - 1]);
            }
        }
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}