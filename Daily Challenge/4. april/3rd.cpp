#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool helper(int i, int j, vector<vector<char>>& board, string word, int index) {
        if (index == word.size())
            return true;
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '*';
        
        bool res = helper(i + 1, j, board, word, index + 1) ||
                   helper(i - 1, j, board, word, index + 1) ||
                   helper(i, j + 1, board, word, index + 1) ||
                   helper(i, j - 1, board, word, index + 1);
        
        board[i][j] = temp; 
        
        return res;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty())
            return false;
        
        int rows = board.size();
        int cols = board[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (helper(i, j, board, word, 0))
                    return true;
            }
        }
        
        return false;
    }
};
