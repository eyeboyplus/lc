#include "./../lc.h"

TreeNode* recursive(const vector<int> &preorder, int parent_idx,
    const vector<int> &inorder, int from, int to) {
    if(parent_idx == preorder.size() || from > to)
        return nullptr;
    int parent_val = preorder[parent_idx];
    int idx = from;
    for(; idx <= to && inorder[idx] != parent_val; ++idx);
    TreeNode *parent = new TreeNode(parent_val);
    parent->left = recursive(preorder, parent_idx + 1, inorder, from, idx - 1);
    // 其中，idx - from + 1 表示左子树节点个数，parent_idx + idx - from + 1则为右子树起始位置
    parent->right = recursive(preorder, parent_idx + idx - from + 1, inorder, idx + 1, to);
    return parent;
}

TreeNode* solution(vector<int> &preorder, vector<int> &inorder) {
    return recursive(preorder, 0, inorder, 0, inorder.size() - 1);
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}