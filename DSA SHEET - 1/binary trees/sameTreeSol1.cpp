#include<iostream>
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
private:
    int check(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return 0;
        if(p == NULL || q == NULL) return -1;
        int leftt = check(p->left, q->left);
        if(leftt == -1) return -1;
        int rightt = check(p->right, q->right);
        if(rightt == -1) return -1;
        if(p->val != q->val) return -1;
        return 0;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q) != -1;
    }
}; 