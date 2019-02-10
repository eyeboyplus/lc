#include "./../lc.h"

ListNode *solution(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(!fast || !fast->next)        // 没有环 
        return nullptr;
    // 有环情况下，分别从相遇点和起始点出发，直到两指针相遇，即为环入口
    fast = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main(int argc, char **argv) {
    ListNode head(1);
    ListNode node(2);
    head.next = &node;
    ListNode *result = solution(&head);
    std::cout << "done.";
    return 0;
}