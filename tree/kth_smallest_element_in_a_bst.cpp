#include "./../lc.h"

int solution(TreeNode *root, int k) {
    TreeNode *ptr = root;
    stack<TreeNode *> stk;
    int cnt = 1;
    while(ptr != nullptr || !stk.empty()) {
        while(ptr) {
            stk.push(ptr);
            ptr = ptr->left;
        }
        ptr = stk.top();
        stk.pop();
        if(cnt == k)
            return ptr->val;
        cnt ++;
        ptr = ptr->right;
    }
    return 0;
}

int main(int argc, char **argv) {
    TreeNode head(1);
    TreeNode n1(2);
    head.right = &n1;
    int res1 = solution(&head, 2);
    std::cout << "done.";
    return 0;
}