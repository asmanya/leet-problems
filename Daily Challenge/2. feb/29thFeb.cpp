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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int flag = 0;
        while(!q.empty()) {
            vector<int> temp;
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(temp.size() == 1) {
                if(flag == 0 && temp[0] % 2 == 0) return false;
                if(flag == 1 && temp[0] % 2 != 0) return false;
            }

            for(int i = 1; i < size; i++) {
                if(flag == 0) {
                    if(temp[i] <= temp[i-1] || temp[i] % 2 == 0) return false;
                } else {
                    if(temp[i] >= temp[i-1] || temp[i] % 2 != 0) return false;
                }
            }

            flag = !flag;
        }

        return true;
    }
};