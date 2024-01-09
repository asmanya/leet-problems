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
    void leafNodes(TreeNode* root, vector<int>& vec) {
        if(root == NULL) {
            return;
        }
        leafNodes(root->left, vec);
        if(root->left == NULL && root->right == NULL) {
            vec.push_back(root->val);
        }
        leafNodes(root->right, vec);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1, vec2;
        leafNodes(root1, vec1);
        leafNodes(root2, vec2);
        if(vec1.size() != vec2.size()) return false;
        for(int i = 0; i < vec2.size(); i++) {
            if(vec1[i] != vec2[i]) {
                return false;
            }
        }
        return true;
    }
};