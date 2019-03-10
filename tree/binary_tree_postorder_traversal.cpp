#include "./../lc.h"

vector<int> solution(TreeNode *root) {
    vector<int> result;
    if(root == nullptr) return result;

    stack<TreeNode*> stack;
    stack.push(root);
    TreeNode *prev = nullptr;
    while(!stack.empty()) {
        TreeNode *node = stack.top();
        if(node->left == nullptr && node->right == nullptr || 
        (prev && (prev == node->left || prev == node->right))) {
            stack.pop();
            result.push_back(node->val);
            prev = node;
        } else {
            if(node->right) stack.push(node->right);
            if(node->left) stack.push(node->left);
        }
    }
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}