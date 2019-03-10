#include "./../lc.h"

TreeNode* solution(TreeNode *root, TreeNode *p, TreeNode *q) {
    if(root->val > p->val && root->val > q->val)
        return solution(root->left, p, q);
    if(root->val < p->val && root->val < q->val)
        return solution(root->right, p, q);
    return root;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}