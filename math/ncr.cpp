#include<bits/stdc++.h>
using namespace std;    
const int MOD = 1e9 + 7;
const int MAX = 1e6; // Adjust size as needed
int ncr(int n,int r){
    if(r > n) return 0;
    if(r == 0 || r == n) return 1;
    r = min(r, n - r); // Use symmetry property
    long long numerator = 1; // n * (n-1) * ... * (n-r+1)
    long long denominator = 1; // r!
    for(int i = 0; i < r; i++){
        numerator = (numerator * (n - i)) % MOD;
        denominator = (denominator * (i + 1)) % MOD;
    }
    // Fermat's Little Theorem for modular inverse
    long long denominator_inv = 1, base = denominator, exp = MOD - 2;
    while(exp){
        if(exp & 1) denominator_inv = (denominator_inv * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return (numerator * denominator_inv) % MOD;
}