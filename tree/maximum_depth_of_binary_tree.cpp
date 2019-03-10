#include "./../lc.h"

void recursive(TreeNode *root, int &result, int level) {
    if(root == nullptr) {
        result = max(result, level);
        return;
    }
    recursive(root->left, result, level + 1);
    recursive(root->right, result, level + 1);
}

int solution(TreeNode *root) {
    int result = 0, level = 0;
    recursive(root, result, level);
    return result;
}

int main(int argc, char **argv) {
    TreeNode head(3);
    TreeNode n1(9);
    TreeNode n2(20);
    TreeNode n3(15);
    TreeNode n4(7);
    head.left = &n1;
    head.right = &n2;
    n2.left = &n3;
    n2.right = &n4;
    int res1 = solution(&head);
    std::cout << "done.";
    return 0;
}