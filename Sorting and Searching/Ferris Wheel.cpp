#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x,idx1,idx2,cont = 0;
    scanf("%d%d",&n,&x);
    vector<int> p(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&p[i]);
    }
    sort(p.begin(),p.end());
    idx1 = 0;
    idx2 = n-1;
    while (idx1 <= idx2) {
        if (p[idx1] + p[idx2] <= x) {
            idx1++;
            idx2--;
        }
        else {
            idx2--;
        }
        cont++;
    }
    printf("%d\n",cont);
    return 0;
}
