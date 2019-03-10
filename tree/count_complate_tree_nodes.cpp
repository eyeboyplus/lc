#include "./../lc.h"

int height(TreeNode *root) {
    if(root == nullptr) return 0;
    return height(root->left) + 1;
}

int solution(TreeNode *root) {
    if(root == nullptr) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh == rh)
        return (1 << lh) - 1 + 1 + solution(root->right);
    else
        return (1 << rh) - 1 + 1 + solution(root->left);
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}