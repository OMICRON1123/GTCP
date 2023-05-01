#include <bits/stdc++.h>
using namespace std;

/*
Usar un array prefix sum para calcular las respuestas
*/

int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    vector<long long> presum(1);
    while(n--) {
        long long a;
        scanf("%lld",&a);
        presum.push_back(presum[presum.size()-1]+a);
    }
    while(q--) {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%lld\n",presum[b]-presum[a-1]);
    }
    return 0;
}
