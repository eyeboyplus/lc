#include "./../lc.h"

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void solution(TreeNode *root) {
    stack<TreeNode*> stk;
    TreeNode *ptr = root, *prev = nullptr, *first = nullptr, *second = nullptr;

    while(ptr || !stk.empty()) {
        while(ptr) {
            stk.push(ptr);
            ptr = ptr->left;
        }
        ptr = stk.top();
        stk.pop();
        if(prev && prev->val > ptr->val) {
            if(first == nullptr)
                first = prev;
            second = ptr;
        }
        
        prev = ptr;
        ptr = ptr->right;
    }
    int tmp = first->val;
    first->val = second->val;
    second->val = tmp;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}