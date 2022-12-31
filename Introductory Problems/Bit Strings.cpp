#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,res = 1;
    const long long MOD = 1e9 + 7;
    scanf("%lld",&n);
    for (int i=0;i<n;i++) {
        res *= 2;
        res -= res > MOD ? MOD : 0;
    }
    printf("%lld\n",res);
    return 0;
}
