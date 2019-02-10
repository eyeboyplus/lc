#include "./../lc.h"

bool solution(ListNode *head) {
    if(head == nullptr) return false;
    ListNode *walker = head;
    ListNode *runner = head;
    while(runner->next != nullptr && runner->next->next != nullptr) {
        walker = walker->next;
        runner = runner->next->next;
        if(walker == runner) return true;
    }
    return false;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}