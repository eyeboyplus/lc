#include "./../lc.h"

void solution(TreeNode *root) {
    if(root == nullptr) return;

    stack<TreeNode*> stack;
    stack.push(root);
    TreeNode head(0);
    TreeNode *ptr = &head;
    while(!stack.empty()) {
        TreeNode *node = stack.top();
        stack.pop();
        ptr->right = node;
        ptr = node;
        if(node->right) stack.push(node->right);
        if(node->left) stack.push(node->left);
        node->left = nullptr;
        node->right = nullptr;
    }
    root = head.right;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}