#include "./../lc.h"

void dfs(TreeNode *root, vector<vector<int>> &result, int level) {
    if(root == nullptr) return;
    if(level == result.size())
        result.push_back(vector<int>());
    result[level].push_back(root->val);
    dfs(root->left, result, level + 1);
    dfs(root->right, result, level + 1);
}

vector<vector<int>> solution(TreeNode* root) {
    vector<vector<int>> ret;
    dfs(root, ret, 0);
    return vector<vector<int>>(ret.rbegin(), ret.rend());
}

// iterative
vector<vector<int>> solution_1(TreeNode *root) {
    vector<vector<int>> result;
    if(root == nullptr) return result;

    queue<TreeNode *> queue;
    queue.push(root);
    while(!queue.empty()){
        int levelNum = queue.size();
        vector<int> vec;
        for(int i = 0; i < levelNum; ++i) {
            TreeNode *node = queue.front();
            vec.push_back(node->val);
            if(node->left)
                queue.push(node->left);
            if(node->right)
                queue.push(node->right);
        }
        result.insert(result.begin(), vec);
    }
    return result;   
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}