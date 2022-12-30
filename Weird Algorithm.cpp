#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    scanf("%lld",&n);
    printf("%lld",n);
    while (n != 1) {
        n = (n&1) == 0 ? n>>1 : n*3+1;
        printf(" %lld",n);
    }
    return 0;
}
