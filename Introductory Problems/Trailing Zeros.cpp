#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,res=0;
    scanf("%lld",&n);
    for (int i=5;i<=n;i+=5) {
        int aux = i;
        while (aux%5 == 0) {
            res++;
            aux /= 5;
        }
    }
    printf("%lld",res);
    return 0;
}
