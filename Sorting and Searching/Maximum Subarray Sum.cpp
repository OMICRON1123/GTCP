#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,sum,best;
    scanf("%lld",&n);
    vector<long long> x(n);
    for (long long i=0;i<n;i++) {
        scanf("%lld",&x[i]);
    }
    best = sum = x[0];
    for (long long i=1;i<n;i++) {
        sum = max(sum+x[i],x[i]);
        best = sum > best ? sum : best;
    }
    printf("%lld\n",best);
    return 0;
}
