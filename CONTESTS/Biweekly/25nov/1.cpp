#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for(int i = 0; i < words.size(); i++) {
            size_t ran = words[i].find(x);
            if(ran != string :: npos) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> words = {"leet","code"};
    vector<int> result = sol.findWordsContaining(words, 'e');
    return 0;
}