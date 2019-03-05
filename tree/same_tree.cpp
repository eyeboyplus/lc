#include "./../lc.h"

bool solution(TreeNode *p, TreeNode *q) {
    if(p == nullptr ^ q == nullptr) return false;
    if(p == nullptr && q == nullptr) return true;

    return solution(p->left, q->left) && p->val == q->val && solution(p->right, q->right);
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}