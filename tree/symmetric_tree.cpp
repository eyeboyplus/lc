#include "./../lc.h"

bool recursive(TreeNode *left, TreeNode *right) {
    if(left == nullptr ^ right == nullptr) return false;
    if(left == nullptr && right == nullptr) return true;

    if(left->val != right->val) return false;
    return recursive(left->left, right->right) && recursive(left->right, right->left);
}

bool solution(TreeNode *root) {
    return (root == nullptr || recursive(root->left, root->right));
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}