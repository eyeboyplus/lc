#include "./../lc.h"

// hashmap
Node* solution(Node *head) {
    if(head == nullptr) return nullptr;
    
    map<Node*, Node*> map;
    Node *ptr = head;
    while(ptr) {
        Node *node = new Node();
        node->val = ptr->val;
        map[ptr] = node;
        ptr = ptr->next;
    }
    ptr = head;
    while(ptr) {
        map[ptr]->next = map[ptr->next];
        map[ptr]->random = map[ptr->random];
        ptr = ptr->next;
    }
    return map[head];
}

int main(int argc, char **argv) {
    Node head;
    head.val = 1;
    Node n1;
    n1.val = 2;
    n1.next = nullptr;
    n1.random = &n1;
    head.next = &n1;
    head.random = &n1;
    std::cout << "done.";
    Node *rest = solution(&head);
    return 0;
}