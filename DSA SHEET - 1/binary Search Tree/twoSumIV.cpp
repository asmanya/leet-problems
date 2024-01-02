#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        set<int> order;
        return check(root, k, order);
    }
    bool check(TreeNode* root, int k, set<int>& order) {
        if(!root) return false;
        if(order.find(root -> val) != order.end()) return true;
        order.insert(k - root -> val);
        return check(root -> left, k, order) || check(root -> right, k, order);
    }
};