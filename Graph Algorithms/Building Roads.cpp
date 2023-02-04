#include <bits/stdc++.h>
using namespace std;

/*
Implementar un Union Find y ver cuántos conjuntos disjuntos hay al final después de
procesar los caminos, luego se miran los caminos faltantes.
*/

class UnionFind;

class UnionFind {
private:
    vector<int> father,weight;

public:
    UnionFind(int x) {
        weight = vector<int>(x);
        father = vector<int>(x);
        for (int i=0;i<x;i++) {
            father[i] = i;
        }
    }

    int ufind(int x) {
        if (father[x] == x) return x;
        return father[x] = ufind(father[x]);
    }

    void join(int x,int y) {
        x = ufind(x);
        y = ufind(y);
        if (x == y) return;
        if (weight[x] < weight[y]) {
            father[x] = y;
        }
        else if (weight[x] > weight[y]) {
            father[y] = x;
        }
        else {
            father[x] = y;
            weight[y]++;
        }
    }
};

int main() {
    int n,m,cont = 0;
    scanf("%d%d",&n,&m);
    UnionFind uf = UnionFind(n);
    vector<pair<int,int>> path;
    set<int> nums;
    while (m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        uf.join(a-1,b-1);
    }
    nums.insert(uf.ufind(0)+1);
    for (int i=1;i<n;i++) {
        if (nums.find(uf.ufind(i)+1) == nums.end()) {
            path.push_back({*nums.begin(),uf.ufind(i)+1});
            nums.insert(uf.ufind(i)+1);
            cont++;
        }
    }
    printf("%d\n",cont);
    for (int i=0;i<cont;i++) {
        printf("%d %d\n",path[i].first,path[i].second);
    }
    return 0;
}
