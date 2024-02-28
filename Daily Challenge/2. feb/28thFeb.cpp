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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> levelOrder;

        q.push(root);

        int size;
        while(!q.empty()) {
            size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                levelOrder.push_back(node->val); 
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return levelOrder[levelOrder.size() - size];
    }
};