#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[2];

    bool containsBit(int bit) {
        return links[bit] != NULL;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit]; 
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }  

    void insert(int num) {
        Node* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsBit(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int findMax(int num) {
        Node* node = root;
        int maxNum = 0;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(node->containsBit(!bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            } else {
                node = node->get(bit);
            }
        }

        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        Trie trie;

        for(auto &it: nums) trie.insert(it);

        for(auto &it: nums) res = max(res, trie.findMax(it));

        return res;
    }
};