#include "./../lc.h"

void reverse(ListNode* start, ListNode *end, int k, ListNode *prev) {
    ListNode *p = start;
    ListNode *nxt = end->next;
    ListNode head(0);
    for(int i = 0; i < k; i++) {
        ListNode *next = p->next;
        p->next = head.next;
        head.next = p;
        p = next;
    }
    start->next = nxt;
    prev->next = head.next;
}

ListNode* reverse(ListNode *head, int k) {
    ListNode hNode(0);
    hNode.next = head;
    ListNode *start = head, *end = head, *prev = &hNode;
    int cnt = 1;
    while(end) {
        if(cnt < k) {
            end = end->next;
            cnt ++;
            continue;
        } else {
            reverse(start, end, k, prev);
            prev = start;
            start = start->next;
            end = start;
            cnt = 1;
        }
    }
    return hNode.next;
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
    ListNode *ret = reverse(&n1, 3);
    std::cout << "done.";
    return 0;
}