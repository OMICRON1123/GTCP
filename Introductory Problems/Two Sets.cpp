#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,res,cont = 0;
    scanf("%lld",&n);
    vector<bool> chosen(n);
    res = n*(n+1)/2;
    if (res%2 == 0) {
        res /= 2;
        printf("YES\n");
        for (int i=n-1;i>=0;i--) {
            if (res == 0) break;
            if (res-i-1 >= 0) {
                chosen[i] = 1;
                cont++;
                res -= i+1;
            }
        }
        printf("%lld\n",cont);
        long long auxcont = cont;
        for (int i=0;i<n;i++) {
            if (chosen[i]){
                printf(auxcont == 1 ? "%d\n" : "%d ",i+1);
                auxcont--;
            }
        }
        printf("%lld\n",n-cont);
        auxcont = n-cont;
        for (int i=0;i<n;i++) {
            if (!chosen[i]) {
                printf(auxcont == 1 ? "%d\n" : "%d ",i+1);
                auxcont--;
            }
        }
    }
    else {
        printf("NO\n");
    }
    return 0;
}
