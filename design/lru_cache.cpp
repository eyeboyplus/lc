#include "./../lc.h"

struct LRUCacheNode {
    LRUCacheNode *prev;
    LRUCacheNode *next;

    int key;
    int value;

    LRUCacheNode() : prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new LRUCacheNode();
        tail = new LRUCacheNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        int value = -1;
        if(mp.find(key) != mp.end()) {
            LRUCacheNode *node = mp[key];
            value = node->value;
            removeFromList(node);
            addToListHead(node);
        }
        return value;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            LRUCacheNode *node = mp[key];
            node->value = value;

            removeFromList(node);
            addToListHead(node);
        } else {
            LRUCacheNode *node = new LRUCacheNode();
            node->value = value;
            node->key = key;
            size ++;

            mp[key] = node;
            addToListHead(node);

            if(size > capacity) {
                // 删除最后一个元素并删除map中对应的键值对
                if(head->next != tail) {
                    LRUCacheNode *target = tail->prev;
                    mp.erase(target->key);
                    removeFromList(target);
                    delete target;
                    target = nullptr;
                }
                size --;
            }
        }
    }

private:
    void removeFromList(LRUCacheNode *node) {
        if(head->next == tail)
            return;
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToListHead(LRUCacheNode *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    map<int, LRUCacheNode*> mp;
    LRUCacheNode *head;
    LRUCacheNode *tail;
    int capacity;
    int size;
};

int main(int argc, char **argv) {
    
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    int v = cache.get(1);
    cache.put(3, 3);
    v = cache.get(2);
    cache.put(4, 4);
    v = cache.get(1);
    v = cache.get(3);
    v = cache.get(4);
    std::cout << "done.";
    return 0;
}