#include "./../lc.h"

TreeNode *recursive(vector<int> &nums, int left, int right) {
    if(right < left) return nullptr;
    int mid = (left + right) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = recursive(nums, left, mid - 1);
    node->right = recursive(nums, mid + 1, right);
    return node;
}

TreeNode* solution(vector<int> &nums) {
    return recursive(nums, 0, nums.size() - 1);
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}