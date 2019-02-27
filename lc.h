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

#endif //LC_LC_H
