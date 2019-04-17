#include "./../lc.h"

ListNode *solution(ListNode *head, int k) {
    if(head == nullptr) return nullptr;
    ListNode *tail = head;
    int len = 1;
    while(tail->next) {
        len ++;
        tail = tail->next;
    }
    tail->next = head;
    if(k %= len) {
        for(int i = 0; i < len - k; i++)
            tail = tail->next;
    }
    ListNode *newList = tail->next;
    tail->next = nullptr;
    return newList;
}

int main(int argc, char **argv) {
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    ListNode *ret = solution(&n1, 2);
    std::cout << "done.";
    return 0;
}