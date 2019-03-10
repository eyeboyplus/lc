#include "./../lc.h"

void dfs(TreeNode *root, int sum, int &result) {
    if(root == nullptr) return;
    sum = sum * 10 + root->val;
    if(root->left == nullptr && root->right == nullptr) 
        result += sum;
    dfs(root->left, sum, result);
    dfs(root->right, sum, result);
}

int solution(TreeNode* root) {
    int result = 0;
    dfs(root, 0, result);
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}