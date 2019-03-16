#include "./../lc.h"

Node* solution(Node *root) {
    if(root == nullptr) return nullptr;
    queue<Node*> queue;
    queue.push(root);
    while(!queue.empty()) {
        int n = queue.size();
        Node* prev =  nullptr;
        for(int i = 0; i < n; i++) {
            Node *node = queue.front();
            queue.pop();
            if(prev)
                prev->next = node;
            prev = node;
            if(node->left) queue.push(node->left);
            if(node->right) queue.push(node->right);
        }
    }
    return root;
}

Node* solution_1(Node *root) {
    Node *level_start = root;
    while(level_start != nullptr) {
        TreeNode *ptr = level_start;
        while(ptr) {
            if(ptr->left != nullptr)
                ptr->left->next = ptr->right;
            if(ptr->right && ptr->next)
                    ptr->right->next = ptr->next->left;
            ptr = ptr->next;
        }
        level_start = level_start->left;
    }
    return root;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}