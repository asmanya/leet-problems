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
    void ways(TreeNode* root, int& count, unordered_map<int, int>& umap) {
        if(!root->left && !root->right) {
            int temp = 0;
            for(auto it: umap) {
                if(it.second % 2 != 0) {
                    temp++;
                }
            }
            if(temp > 1) {
                return;
            } else {
                count++;
                return;
            }
        }
        if(root->left) {
            umap[root->left->val]++;
            ways(root->left, count, umap);
            umap[root->left->val]--;
        }

        if(root->right) {
            umap[root->right->val]++;
            ways(root->right, count, umap);
            umap[root->right->val]--;
        }
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;

        if(!root->left && !root->right) return 1;

        unordered_map<int, int> umap;
        umap[root->val]++;
        ways(root, count, umap);

        return count;
    }
};