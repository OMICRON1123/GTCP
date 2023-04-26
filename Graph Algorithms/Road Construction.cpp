#include <bits/stdc++.h>
using namespace std;

/*
Usar union find para mantenerse al tanto de los tamaños de las ciudades,
y de cuántas componentes de ciudades hay
*/

class UnionFind;

class UnionFind{
public:
    vector<int> fat,wei,tam;

    UnionFind(int sz) {
        fat = wei = vector<int>(sz+1);
        tam = vector<int>(sz+1,1);
        for (int i=1;i<=sz;i++) {
            fat[i] = i;
        }
    }

    int father(int x) {
        if (x == fat[x]) return x;
        return fat[x] = father(fat[x]);
    }

    void join(int x,int y) {
        x = father(x);
        y = father(y);
        if (x == y) return;
        if (wei[x] >= wei[y]) {
            fat[y] = x;
            tam[x] += tam[y];
            if (wei[x] == wei[y]) wei[x]++;
        }
        else {
            fat[x] = y;
            tam[y] += tam[x];
        }
    }

    bool connected(int x,int y) {
        return father(x) == father(y);
    }
};

int main() {
    int n,m,a,b,M=1;
    scanf("%d%d",&n,&m);
    UnionFind uf = UnionFind(n);
    while (m--) {
        scanf("%d%d",&a,&b);
        if (uf.connected(a,b)) {
            printf("%d %d\n",n,M);
        }
        else {
            a = uf.father(a);
            b = uf.father(b);
            uf.join(a,b);
            M = max(M,max(uf.tam[a],uf.tam[b]));
            printf("%d %d\n",--n,M);
        }
    }
    return 0;
}
