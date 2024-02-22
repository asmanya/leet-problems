#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // for applying Sieve algo - using this prime array
    bool prime[10000000];
    
    // using these vectors for keeping directions
    vector<int> dx{0, 1, 1, 1, 0, -1, -1, -1};
    vector<int> dy{1, 1, 0, -1, -1, -1, 0, 1};
    
    // map for hashing
    map<int, int> mp;
    
    // implementing the Sieve algorithm
    void Sieve() {
        int n = 999999;
        memset(prime, true, sizeof(prime)); // setting all values to true
        for(int p = 2; p * p < n; p++) {
            if(prime[p] == true) {
                for(int i = p * p; i < n; i += p) {
                    prime[i] = false;
                }
            }
        }
    }
    
    // function that goes in a particular direction recursively, increase the number
    // checks if it is prime or not, if it is, increase the count in map
    void solve(int i, int j, int m, int n, int s, vector<vector<int>>& mat, int k) {
        if( i < 0 || j < 0 || i >= n || j >= m) return;
        
        s = 10 * s + mat[i][j];
        if(s > 10 && prime[s]) {
            mp[s]++;
        }

        solve(i + dx[k], j + dy[k], m, n, s, mat, k);
    }
    
    // main function that excecutes every other func
    int mostFrequentPrime(vector<vector<int>>& mat) {
        Sieve();
        int n = mat.size(), m = mat[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < 8; k++) {
                    solve(i, j, m, n, 0, mat, k);
                }
            }
        }
        
        int mx = 0;
        for(auto i: mp) {
            mx = max(mx, i.second);
        }
        if(mx == 0) return -1;
        
        int ans = 0;
        for(auto i: mp) {
            if(i.second == mx) {
                ans = max(ans, i.first);
            }
        }
        
        return ans;
    }
};