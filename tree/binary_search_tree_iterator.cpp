#include "./../lc.h"

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode *p = root;
        while(p) {
            stack.push(p);
            p = p->left;
        }
    }

    int next() {
        int ret = 0;
        if(!stack.empty()) {
            TreeNode *node = stack.top();
            ret = node->val;
            TreeNode *p = node->right;
            while(p) {
                stack.push(p);
                p = p->left;    
            }
        }
        return ret;
    }

    bool hasNext() {
        return !stack.empty();
    }

private:
    stack<TreeNode*> stack;
};

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}