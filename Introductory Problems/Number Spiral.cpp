#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t,x,y,n;
    scanf("%lld",&t);
    while (t--) {
        scanf("%lld%lld",&y,&x);
        if (x >= y) {
            n = (x&1) == 0 ? (x-1)*(x-1)+y : x*x-y+1;
        }
        else {
            n = (y&1) == 0 ? y*y-x+1 : (y-1)*(y-1)+x;
        }
        printf("%lld\n",n);
    }
    return 0;
}
