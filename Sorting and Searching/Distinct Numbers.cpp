#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,aux,cont = 1;
    scanf("%d",&n);
    vector<int> x(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&x[i]);
    }
    sort(x.begin(),x.end());
    aux = x[0];
    for (int i=1;i<n;i++) {
        if (x[i] != aux) {
            cont++;
            aux = x[i];
        }
    }
    printf("%d\n",cont);
    return 0;
}
