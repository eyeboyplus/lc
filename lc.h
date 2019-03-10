//
// Created by eyeboy on 2019/1/24.
//

#ifndef LC_LC_H
#define LC_LC_H

#include <climits>
#include <cmath>

#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(nullptr) {}
};

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() {}
    Node(int _val, Node* _left, Node *_right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

#endif //LC_LC_H
