#include "./../lc.h"

// recursive
vector<int> solution_1(TreeNode *root) {
    vector<int> result;
    if(root == nullptr) return result;

    vector<int> lvec = solution_1(root->left);
    result.insert(result.end(), lvec.begin(), lvec.end());
    result.insert(result.end(), root->val);
    vector<int> rvec = solution_1(root->right);
    result.insert(result.end(), rvec.begin(), rvec.end());
    return result;
}

// iterative
vector<int> solution_2(TreeNode *root) {
    vector<int> result;
    if(root == nullptr) return result;

    stack<TreeNode*> stack;
    TreeNode *ptr = root;
    while(ptr != nullptr || !stack.empty()){
        while(ptr != nullptr) {
            stack.push(ptr);
            ptr = ptr->left;
        }
        TreeNode *node = stack.top();
        stack.pop();
        result.push_back(node->val);
        ptr = node->right;
    }
    return result; 
}

int main(int argc, char **argv) {
    


    std::cout << "done.";
    return 0;
}