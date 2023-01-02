#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k,idxa = 0,idxb = 0, cont = 0;
    scanf("%d%d%d",&n,&m,&k);
    vector<int> a(n),b(m);
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0;i<m;i++) {
        scanf("%d",&b[i]);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    while (idxa < n && idxb < m) {
        if (abs(a[idxa] - b[idxb]) <= k) {
            cont++;
            idxa++;
            idxb++;
        }
        else if (a[idxa] > b[idxb]) {
            idxb++;
        }
        else {
            idxa++;
        }
    }
    printf("%d\n",cont);
    return 0;
}
