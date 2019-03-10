#include "./../lc.h"

int dfs(TreeNode *root, int &result) {
    if(root == nullptr) return 0;
    int left = max(0, dfs(root->left, result));
    int right = max(0, dfs(root->right, result));
    result = max(result, left + right + root->val);
    return max(left, right) + root->val;
}

int solution(TreeNode *root) {
    int result = INT_MIN;
    dfs(root, result);
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}