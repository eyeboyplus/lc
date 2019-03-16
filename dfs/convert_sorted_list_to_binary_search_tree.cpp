#include "./../lc.h"

TreeNode* recursive(ListNode *head, ListNode *tail) {
    if(head == tail) return nullptr;
    if(head->next == tail) {
        TreeNode *root = new TreeNode(head->val);
        return root;
    }

    ListNode *mid = head, *ptr = head;
    while(ptr != tail && ptr->next != tail) {
        mid = mid->next;
        ptr = ptr->next->next;
    }
    TreeNode *root = new TreeNode(mid->val);
    root->left = recursive(head, mid);
    root->right = recursive(mid->next, tail);
    return root;
}

TreeNode* solution(ListNode *head) {

}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}