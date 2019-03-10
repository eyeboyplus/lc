#include "./../lc.h"

void dfs(TreeNode *root, string path, vector<string> &result) {
    if(root == nullptr) return;

    path += to_string(root->val);

    if(root->left == nullptr && root->right == nullptr) {
        result.push_back(path);
        return;
    } else {
        path += "->";
    }

    dfs(root->left, path, result);
    dfs(root->right, path, result);
}

vector<string> solution(TreeNode *root) {
    vector<string> ret;
    string path;
    dfs(root, path, ret);
    return ret;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}