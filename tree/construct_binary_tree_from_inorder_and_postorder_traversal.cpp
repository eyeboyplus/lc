#include "./../lc.h"

TreeNode *recursive(const vector<int> &inorder, int from, int to,
    const vector<int> &postorder, int pstart) {
        if(pstart < 0 || from > to)
            return nullptr;
        int pval = postorder[pstart];
        int idx = to;
        for(;idx >= from && inorder[idx] != pval; --idx);
        TreeNode *parent = new TreeNode(pval);
        parent->left = recursive(inorder, from, idx - 1, postorder, pstart - (to - idx + 1));
        parent->right = recursive(inorder, idx + 1, to, postorder, pstart - 1);
        return parent;
    }

TreeNode *solution(vector<int> &inorder, vector<int> &postorder) {
    return recursive(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1);
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}