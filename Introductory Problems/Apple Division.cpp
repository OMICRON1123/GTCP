#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    vector<long long> p(n);
    long long res = 1e13;
    for (int i=0;i<n;i++) {
        scanf("%lld",&p[i]);
    }
    for (int i=0;i<(1<<n);i++) {
        long long sum1 = 0, sum2 = 0;
        for (int j=0;j<n;j++) {
            if (((1<<j)&i))
                sum1+=p[j];
            else
                sum2+=p[j];
        }
        res = abs(sum1-sum2) < res ? abs(sum1-sum2) : res;
    }
    printf("%lld\n",res);
    return 0;
}
