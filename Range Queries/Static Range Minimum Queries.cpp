#include <bits/stdc++.h>
using namespace std;

/*
Usar una sparse table para calcular las respuestas.
*/

int greatestpow2(int num) {
    int t=0;
    while ((1<<t) <= num) t++;
    t--;
    return t;
}

int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    vector<int> x(n);
    vector<vector<int>> sparse;
    for (int i=0;i<n;i++) {
        scanf("%d",&x[i]);
    }
    sparse.push_back(x);
    for (int t=1;(1<<t)<=x.size();t++) {
        vector<int> aux;
        for (int i=0;i+(1<<t)<=x.size();i++) {
            aux.push_back(min(sparse[t-1][i],sparse[t-1][i+(1<<(t-1))]));
        }
        sparse.push_back(aux);
    }
    while (q--) {
        int a,b,aux;
        scanf("%d%d",&a,&b);
        aux = b-a+1;
        aux = greatestpow2(aux);
        int ans = min(sparse[aux][a-1],sparse[aux][b-(1<<aux)]);
        printf("%d\n",ans);
    }
    return 0;
}
