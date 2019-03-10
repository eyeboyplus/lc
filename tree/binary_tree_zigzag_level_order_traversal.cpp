#include "./../lc.h"

vector<vector<int>> solution(TreeNode *root) {
    vector<vector<int>> result;
    if(root == nullptr) return result;

    queue<TreeNode*> queue;
    queue.push(root);
    bool reversed = false;
    while(!queue.empty()) {
        int n = queue.size();
        vector<int> vec(n);
        for(int i = 0; i < n; ++i) {
            TreeNode *node = queue.front();
            queue.pop();
            
            int index = reversed ? n - 1 - i : i;
            vec[index] = node->val;

            if(node->left) queue.push(node->left);
            if(node->right) queue.push(node->right);
        }
        result.push_back(vec);
        reversed = !reversed;
    }
    return result;
}

int main(int argc, char **argv) {
    TreeNode head(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    head.left = &n2;
    head.right = &n3;
    n2.left = &n4;
    n3.right = &n5;
    vector<vector<int>> res = solution(&head);
    std::cout << "done.";
    return 0;
}