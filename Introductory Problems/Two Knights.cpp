#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    scanf("%lld",&n);
    for (long long i = 1;i<=n;i++) {
        printf("%lld\n",((i*i*i*i-9*i*i+24*i-16)>>1));
    }
    return 0;
}
