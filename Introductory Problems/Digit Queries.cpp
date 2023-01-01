#include <bits/stdc++.h>
using namespace std;

vector<long long> power;

vector<int> digits(long long n) {
    vector<int> aux;
    while (n > 0) {
        aux.push_back(n%10);
        n /= 10;
    }
    reverse(aux.begin(),aux.end());
    return aux;
}

int main() {
    long long aux = 10;
    power.push_back(9);
    for (int i=2;aux < 1e17;i++) {
        power.push_back(power[i-2]+9*i*aux);
        aux *= 10;
    }
    //for (int i=0;i<power.size();i++) printf("%lld ",power[i]); printf("\n");

    long long q,k;
    scanf("%lld",&q);
    while (q--) {
        scanf("%lld",&k);
        int idx = 0;
        for (int i=0;i<power.size();i++) {
            if (k <= power[i]) {
                idx = i;
                break;
            }
        }
        int u;
        k -= idx > 0 ? power[idx-1]+1 : 0;
        u = k%(idx+1);
        aux = 1;
        for (int i=0;i<idx;i++) {
            aux *= 10;
        }
        k /= (idx+1);
        k += aux > 1 ? aux : 0;
        vector<int> digit = digits(k);
        printf("%d\n",digit[u]);
    }
    return 0;
}
