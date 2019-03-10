#include "./../lc.h"

vector<int> solution(TreeNode *root) {
    vector<int> ret;
    if(root == nullptr) return ret;
    queue<TreeNode *> que;
    que.push(root);
    while(!que.empty()) {
        int n = que.size();
        for(int i = 0; i < n; i++) {
            TreeNode * node = que.front();
            que.pop();
            if(i == n - 1)
                ret.push_back(node->val);
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
    }
    return ret;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}