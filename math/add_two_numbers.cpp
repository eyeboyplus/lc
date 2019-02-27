#include "./../lc.h"

ListNode* solution(ListNode* l1, ListNode* l2) {
    ListNode *ptr1 = l1, *ptr2 = l2;
    ListNode header(0);
    ListNode *parent = &header;
    int div = 0;
    while(ptr1 != nullptr && ptr2 != nullptr) {
        int sum = ptr1->val + ptr2->val + div;
        ListNode *node = new ListNode(sum % 10);
        parent->next = node;
        parent = node;
        div = sum / 10;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    while(ptr1 != nullptr) {
        int sum = ptr1->val + div;
        ListNode *node = new ListNode(sum % 10);
        parent->next = node;
        parent = node;

        div = sum / 10;
        ptr1 = ptr1->next;
    }
    while(ptr2 != nullptr) {
        int sum = ptr2->val + div;
        ListNode *node = new ListNode(sum % 10);
        div = sum / 10;

        parent->next = node;
        parent = node;

        ptr2 = ptr2->next;
    }

    if(div > 0) {
        ListNode *node = new ListNode(div);
        parent->next = node;
        parent = node;
    }
    return header.next;    
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}