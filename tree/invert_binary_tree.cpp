#include "./../lc.h"

TreeNode* solution(TreeNode *root) {
    if(root) {
        solution(root->right);
        solution(root->left);
        swap(root->left, root->right);
    }
    return root;
}

TreeNode *solution_1(TreeNode *root) {
    stack<TreeNode*> stack;
    stack.push(root);
    while(!stack.empty()) {
        TreeNode *node = stack.top();
        stack.pop();
        if(node) {
            stack.push(node->left);
            stack.push(node->right);
            swap(node->left, node->right);
        }
    }
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}