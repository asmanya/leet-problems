#include<bits/stdc++.h>
using namespace std;

// Sieve algorithm is used to check or get the primes

int countPrimes(int n) {
    int prime[n + 1] = {0};
    for(int i = 2; i * i < n; i++) {
        if(prime[i] == 0) {
            for(int j = i * i; j < n; j += i) {
                prime[j] = 1;
            }
        }
    }

    int count = 1;
    for(int i = 2; i < n; i++) {
        if(prime[i] == 0) count++;
    }

    return count;
}

int main()
{
    cout << "Enter a number." << endl;
    int n;
    cin >> n;
    cout << countPrimes(n); 
    return 0;
}