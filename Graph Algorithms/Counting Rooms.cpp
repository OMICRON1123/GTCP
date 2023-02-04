#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se implementa un union find, si un punto está debajo de otro
o al lado se unen sus conjuntos, hay que contar cuántos conjuntos distintos hay al
final, el mapa que originalmente es una matriz se puede tratar como un vector
trabajando con las operaciones de división y módulo.
*/

class UnionFind;

class UnionFind {
public:
    vector<int> father,weight;

    UnionFind(int x) {
        weight = vector<int>(x);
        father = vector<int>(x);
        for (int i=0;i<x;i++) {
            father[i] = i;
        }
    }

    int ufind(int x) {
        if (x == father[x]) return x;
        return father[x] = ufind(father[x]);
    }

    void join(int x,int y) {
        x = ufind(x);
        y = ufind(y);
        if (x == y) return;
        if (weight[x] < weight[y]) {
            father[x] = y;
            weight[y]++;
        }
        else {
            father[y] = x;
            weight[x]++;
        }
    }

    bool connected(int x,int y) {
        return ufind(x) == ufind(y);
    }
};

int main() {
    int n,m;
    long long cont = 0;
    scanf("%d%d",&n,&m);
    UnionFind uf = UnionFind(n*m);
    vector<vector<bool> > grid(n,vector<bool>(m));
    set<int> nums;
    for (int i=0;i<n;i++) {
        string s;
        cin>>s;
        for (int j=0;j<m;j++) {
            if (s[j] == '.') {
                grid[i][j] = 1;
            }
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (grid[i][j]) {
                if (j+1 < m && grid[i][j+1]) uf.join(i*m+j,i*m+j+1);
                if (i+1 < n && grid[i+1][j]) uf.join(i*m+j,(i+1)*m+j);
            }
        }
    }
    for (int i=0;i<n*m;i++) {
        if (grid[i/m][i%m] && nums.find(uf.ufind(i)) == nums.end()) {
            nums.insert(uf.ufind(i));
            cont++;
        }
    }
    printf("%lld\n",cont);
    return 0;
}
