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
    int diameter(TreeNode* root, int& dia) {
        if(root == NULL) {
            return 0;
        }
        int lh = diameter(root->left, dia);
        int rh = diameter(root->right, dia);
        dia = max(lh + rh, dia);
        return max(lh, rh) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        diameter(root, dia);
        return dia;
    }
};