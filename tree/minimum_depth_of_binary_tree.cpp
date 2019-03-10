#include "./../lc.h"

void recursive(TreeNode *root, int &result, int level) {
    if(!root->right && !root->left) {
        result = min(result, level);
        return;
    }

    if(root->left)
        recursive(root->left, result, level + 1);
    if(root->right)
        recursive(root->right, result, level + 1);
}

int solution(TreeNode *root) {
    if(root == nullptr) return 0;

    int result = INT_MAX;
    recursive(root, result, 1);
    return result;
}

int solution_1(TreeNode *root) {
    if(root == nullptr) return 0;
    int l = solution_1(root->left);
    int r = solution_1(root->right);
    return (l == 0 || r == 0) ? l + r + 1 : min(l, r) + 1;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}