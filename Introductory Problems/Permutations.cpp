#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    if (n == 1) {
        printf("1\n");
    }
    else if (n <= 3) {
        printf("NO SOLUTION\n");
    }
    else {
        printf("%d",n-1);
        for (int i = n-3;i >= 1; i -= 2) {
            printf(" %d",i);
        }
        for (int i=n;i>=1;i-=2) {
            printf(" %d",i);
        }
    }
    return 0;
}
