#include "./../lc.h"

int solution(vector<int> &height) {
    int result = 0;
    int left = 0, right = height.size() - 1;
    while(left < right) {
        int h = min(height[left], height[right]);
        result = max(result, (right - left) * h);
        // 左右边界向中间寻找比当前高度更高边界，才有可能比历史最大容量更大
        while(height[left] <= h && left < right) left++;
        while(height[right] <= h && left < right) right--;   
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}