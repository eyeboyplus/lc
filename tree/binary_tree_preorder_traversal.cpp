#include "./../lc.h"

vector<int> solution(TreeNode *root) {
    vector<int> result;
    if(root == nullptr) return result;

    stack<TreeNode*> stack;
    stack.push(root);
    while(!stack.empty()) {
        TreeNode *node = stack.top();
        stack.pop();
        result.push_back(node->val);
        if(node->right) stack.push(node->right);
        if(node->left) stack.push(node->left);
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}