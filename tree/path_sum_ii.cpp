#include "./../lc.h"

void dfs(TreeNode *root, vector<vector<int>> &result, vector<int> path, int sum) {
    if(root == nullptr) return;
    if(root->left == nullptr && root->right == nullptr) {
        if(sum == root->val) {
            path.push_back(root->val);
            result.push_back(path);
        }
        return;
    }
    
    path.push_back(root->val);

    dfs(root->left, result, path, sum - root->val);
    dfs(root->right, result, path, sum - root->val);
}

vector<vector<int>> solution(TreeNode *root, int sum) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(root, result, path, sum);
    return result;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}