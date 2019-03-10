#include "./../lc.h"

int depth(TreeNode *root) {
    if(root == nullptr) return 0;
    return max(depth(root->left), depth(root->right)) + 1;
}

bool solution(TreeNode *root) {
    if(root == nullptr) return true;
    int l = depth(root->left);
    int r = depth(root->right);
    return abs(l - r) <= 1 && solution(root->left) && solution(root->right);
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}