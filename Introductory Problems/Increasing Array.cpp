#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long cont = 0;
    scanf("%d",&n);
    vector<long long> x(n);
    scanf("%d",&x[0]);
    for (int i=1;i<n;i++) {
        scanf("%lld",&x[i]);
        if (x[i-1] > x[i]) {
            cont += x[i-1] - x[i];
            x[i] = x[i-1];
        }
    }
    printf("%lld",cont);
    return 0;
}
