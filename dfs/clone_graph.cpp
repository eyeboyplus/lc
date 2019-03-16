#include "./../lc.h"

unordered_map<Node*, Node*> copies;

Node* solution(Node* node) {
    if(node == nullptr)
        return nullptr;

    if(copies.find(node) == copies.end()) {
        copies[node] = new Node(node->val, {});
        for(Node *neighbor : node->neighbors) {
            copies[node]->neighbors.push_back(solution(neighbor));
        }
    }
    return copies[node];
}



int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}