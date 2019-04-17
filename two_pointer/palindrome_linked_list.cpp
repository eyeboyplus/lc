#include "./../lc.h"

ListNode* reverse(ListNode *head) {
    ListNode *ptr = head;
    ListNode h(0);
    while(ptr) {
        ListNode* next = ptr->next;
        ptr->next = h.next;
        h.next = ptr;
        ptr = next;
    }
    return h.next;
}

bool solution(ListNode *head) {
    if(head == nullptr || head->next == nullptr) return true;
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = reverse(slow->next);
    while(head && slow) {
        if(head->val != slow->val) return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}

int main(int argc, char **argv) {
    ListNode head(1);
    ListNode n1(2);
    ListNode n2(2);
    ListNode n3(1);
    head.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    bool ret = solution(&head);
    std::cout << "done.";
    return 0;
}