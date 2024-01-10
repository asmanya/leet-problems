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
    void modifyTree(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*>& parents, TreeNode* &srcNode) {
        if(root == NULL) return;
        if(root->left) parents[root->left] = root;
        if(root->right) parents[root->right] = root;

        if(root->val == start) srcNode = root;

        modifyTree(root->left, start, parents, srcNode);
        modifyTree(root->right, start, parents, srcNode);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
         if (root == nullptr)
            return 0;

        unordered_map<TreeNode *, TreeNode *> parents; // map front node to parent
        TreeNode *srcNode = nullptr;

        parents[root] = nullptr;

        modifyTree(root, start, parents, srcNode);

        unordered_set<TreeNode *> vis;
        vis.insert(srcNode);

        queue<TreeNode *> q;
        q.push(srcNode);

        int count = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();

                if (node->left && vis.find(node->left) == vis.end()) {
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if (node->right && vis.find(node->right) == vis.end()) {
                    q.push(node->right);
                    vis.insert(node->right);
                }
                if (parents[node] != nullptr && vis.find(parents[node]) == vis.end()) {
                    q.push(parents[node]);
                    vis.insert(parents[node]);
                }
            }
            count++;
        }

        return count - 1;
    }
};