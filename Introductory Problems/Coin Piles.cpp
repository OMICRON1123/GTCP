#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,a,b;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&a,&b);
        if (2*a - b >= 0 && (2*a - b)%3 == 0 && 2*b - a >= 0 && (2*b - a)%3 == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
