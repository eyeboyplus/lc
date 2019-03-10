#include "./../lc.h"

bool solution(TreeNode *root) {
    TreeNode *ptr = root;
    stack<TreeNode *> stack;
    TreeNode *prev = nullptr;
    while(ptr != nullptr && !stack.empty()) {
        while(ptr != nullptr) {
            stack.push(ptr);
            ptr = ptr->left;
        }
        TreeNode *node = stack.top();
        stack.pop();
        if(prev != nullptr && prev->val >= node->val) return false;
        prev = node;
        ptr = node->right;
    }
    return true;
}

int main(int argc, char **argv) {
    TreeNode head(5);
    TreeNode n1(1);
    TreeNode n2(4);
    TreeNode n3(3);
    TreeNode n4(6);
    head.left = &n1;
    head.right = &n2;
    n2.left = &n3;
    n2.right = &n4;
    bool res = solution(&head);
    std::cout << "done.";
    return 0;
}