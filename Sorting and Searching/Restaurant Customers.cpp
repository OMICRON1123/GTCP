#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,idxa = 0,idxb = 0,cont = 0,best = 0;
    scanf("%d",&n);
    vector<int> a(n),b(n);
    for (int i=0;i<n;i++) {
        scanf("%d%d",&a[i],&b[i]);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    while (idxa < n) {
        if (a[idxa] < b[idxb]) {
            cont++;
            best = cont > best ? cont : best;
            idxa++;
        }
        else if (a[idxa] > b[idxb]) {
            cont--;
            idxb++;
        }
    }
    printf("%d\n",best);
    return 0;
}
