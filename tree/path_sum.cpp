#include "./../lc.h"

bool solution(TreeNode *root, int sum) {
    if(root == nullptr) return false;

    if(root->val == sum && root->left == nullptr && root->right == nullptr) return true;

    return solution(root->left, sum - root->val) || solution(root->right, sum - root->val);
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}