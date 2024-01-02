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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* valNode = new TreeNode(val);
        TreeNode* pointer = root;
        TreeNode* present = nullptr;

        while(pointer) {
            present = pointer;
            if(val > pointer->val) {
                pointer = pointer->right;
            }
            else {
                pointer = pointer->left;
            }
        }

        if (!present) {
            return valNode;
        }

        if (present->val > val){
            present->left = valNode;
        } 
        else {
            present->right = valNode;
        }
        return root;
    }
};