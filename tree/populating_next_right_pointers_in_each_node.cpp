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

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}