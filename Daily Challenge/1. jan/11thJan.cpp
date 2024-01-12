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
    // pair { storesMin, storesMax}

    pair<int, int> func(TreeNode* root, int& ans) {
        if(!root) return {INT_MAX, INT_MIN};

        pair<int, int> leftMinMax = func(root->left, ans);
        pair<int, int> rightMinMax = func(root->right, ans);

        int localMin = min(root->val, min(leftMinMax.first, rightMinMax.first));
        int localMax = max(root->val, max(leftMinMax.second, rightMinMax.second));

        ans = max(ans, max(abs(root->val - localMin), abs(root->val - localMax)));
        return {localMin, localMax};
    }
    
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = INT_MIN;
        func(root, ans);
        return ans; 
    }
};