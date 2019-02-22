#include "./../lc.h"

vector<TreeNode*> generateSubtrees(int s, int e) {
    vector<TreeNode*> result;
    if(s > e) {
        result.push_back(nullptr);
        return result;
    }
    for(int i = s; i <= e; ++i) {
        vector<TreeNode*> leftSubtrees = generateSubtrees(s, i - 1);
        vector<TreeNode*> rightSubtrees = generateSubtrees(i + 1, e);

        // 左右子树集合组合
        for(vector<TreeNode*>::iterator left = leftSubtrees.begin();
            left != leftSubtrees.end(); left++) {
            for(vector<TreeNode*>::iterator right = rightSubtrees.begin();
                right != rightSubtrees.end(); right++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = *left;
                    root->right = *right;
                    result.push_back(root);
            }
        }
    }
    return result;
}

vector<TreeNode*> solution(int n) {
    if(n == 0) return {};

    return generateSubtrees(1, n);
}

int main(int argc, char **argv) {
    vector<TreeNode*> res1 = solution(0);
    std::cout << "done.";
    return 0;
}