#include "./../lc.h"

TreeNode* solution(TreeNode *root, TreeNode *p, TreeNode *q) {
    if(root == nullptr || root == p || root == q) return root;
    TreeNode *l = solution(root->left, p, q);
    TreeNode *r = solution(root->right, p, q);
    if(l != nullptr && r != nullptr) return root;
    return l != nullptr ? l : r;
}

int main(int argc, char **argv) {
    TreeNode head(3);
    TreeNode n1(5);
    TreeNode n2(1);
    TreeNode n3(6);
    TreeNode n4(2);
    TreeNode n5(0);
    TreeNode n6(8);
    TreeNode n7(7);
    TreeNode n8(4);
    head.left = &n1;
    head.right = &n2;
    n1.left = &n3;
    n1.right = &n4;
    n2.left = &n5;
    n2.right = &n6;
    n4.left = &n7;
    n4.right = &n8;
    std::cout << "done.";
    return 0;
}