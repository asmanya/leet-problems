#include<bits/stdc++.h>
using namespace std;


// RABIN KARP ALGORITHM


class Solution {
private:
    // using base for module function so that calculated hash function value do not overflow
    int Base = 1000000;

    // Rabin_karp algo takes two strings as input for matching
    int Rabin_karp(string source, string target) {
        // if either target or source is empty, they cannot be matched thus -1 is returned
        if(source == "" || target == "") return -1;

        // we take size of target and power to generate the hash func
        int m = target.size();
        int power = 1;

        // we generate hash func with power of 31 - max value of power the will be as
        for(int i = 0; i < m; i++) {
            power = (power * 31) % Base;
        }

        // initializing target hash value as 0 - this is calculated using the hash function which is defined below
        // this is the hash value for target which we will search in source
        int targetCode = 0;

        for(int i = 0; i < m; i++) {
            // hash function to calculate hash value
            targetCode = (targetCode * 31 + target[i]) % Base;
        }

        // this will store the calculated hash Value when traversal will be done in source code
        int hashCode = 0;

        // traversing throughh the source to find the matching targetCode value
        for(int i = 0; i < source.size(); i++) {
            // using hash function to find the hashCode for string which is atleast of size of target string
            hashCode = (hashCode * 31 + source[i]) % Base;

            // continuing this till the full initial value of hashCode is obtained
            if(i < m-1) continue;

            // now we use rolling window, when we exceed the size of target string, even though we add the next character to hashCode
            // the first element from left needs to be removed, which will have power times more value as per hash function
            if(i >= m) {
                hashCode = (hashCode - source[i-m] * power) % Base;
            }

            // incase value of hashCode becomes neg, we add Base to it, to return to value before module
            if(hashCode < 0) {
                hashCode += Base;
            }

            // if in case hashCode and targetCode is same, we compare the strings
            if(hashCode == targetCode) {
                // if source contains a substr of size m which equals target, we return a value not equal to -1
                if(source.substr(i-m+1, m) == target) return i - m + 1;
            }
        }

        // if the value is not found then we return a -1
        return -1;

    }

public:
    int repeatedStringMatch(string a, string b) {
        // if given strings are same, then a is required only once
        if(a == b) return 1;

        // otherwise, lets have another string source that is formed used string a
        // maintain a count of how many times string a is used
        int count = 1;
        string source = a;

        // while size of source is less than b, b cannot be substr of source, thus count is increased, and a is added to source
        while(source.size() < b.size()) {
            count++;
            source += a;
        }

        // if in case source becomes equal to string b, we return the count
        if(source == b) return count;

        // otherwise we perform string matching using RABIN KARP ALGORITHM - we perform it by hashing the strings
        if(Rabin_karp(source, b) != -1) return count;
        if(Rabin_karp(source + a, b) != -1) return count + 1;

        // returning -1 if string b cannot be formed from string a
        return -1;
    }
};