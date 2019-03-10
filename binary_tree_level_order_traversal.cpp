#include "./../lc.h"

vector<vector<int>> solution(TreeNode *root) {
    queue<TreeNode*> queue;
    vector<vector<int>> result;
    if(root == nullptr) return result;
    queue.push(root);
    while(!queue.empty()){
        int n = queue.size();
        vector<int> vec;
        for(int i = 0; i < n; ++i) {
            TreeNode *node = queue.front();
            queue.pop();
            vec.push_back(node->val);
            if(node->left) queue.push(node->left);
            if(node->right) queue.push(node->right);
        }
        result.push_back(vec);
    }
    return result;
}

vector<vector<int>> solution_1(TreeNode *root) {

}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}