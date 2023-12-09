#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0, count10 = 0;
        // sort(bills.begin(), bills.end());
        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5){
                count5++;
            }
            else if(bills[i] == 10) {
                if(count5 > 0) {
                    count5--;
                }
                else {
                    return false;
                }
                count10++;
            }
            else {
                if(count10 > 0 && count5 > 0) {
                    count10--;
                    count5--;
                }else if(count10 == 0 && count5 >= 3) {
                    count5--;
                    count5--;
                    count5--;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};