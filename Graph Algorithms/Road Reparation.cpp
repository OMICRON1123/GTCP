#include <bits/stdc++.h>
using namespace std;

/*
Minimum Spanning Tree
*/

class UnionFind;

class UnionFind{
public:
    int sz;
    vector<int> fat,wei;

    UnionFind(int sz) {
        this->sz = sz;
        fat = wei = vector<int>(sz+1);
        for (int i=1;i<=sz;i++) fat[i] = i;
    }

    int father(int x) {
        if (fat[x] == x) return x;
        return fat[x] = father(fat[x]);
    }

    void join(int x,int y) {
        x = father(x);
        y = father(y);
        if (x == y) return;
        if (wei[x] > wei[y]) {
            fat[y] = x;
        }
        else if (wei[x] < wei[y]) {
            fat[x] = y;
        }
        else {
            fat[y] = x;
            wei[x]++;
        }
    }

    bool connected(int x,int y) {
        return father(x) == father(y);
    }
};

int main() {
    bool ok = 1;
    int n,m;
    long long sum = 0;
    scanf("%d%d",&n,&m);
    vector<tuple<int,int,int>> edge(m);
    UnionFind uf = UnionFind(n);
    for (int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edge[i] = make_tuple(a,b,c);
    }
    sort(edge.begin(),edge.end(),[](tuple<int,int,int> t1,tuple<int,int,int> t2) {
         return get<2>(t1) < get<2>(t2);
    });
    for (int i=0;i<m;i++) {
        int a,b,c;
        tie(a,b,c) = edge[i];
        if (!uf.connected(a,b)) {
            sum += c;
            uf.join(a,b);
            n--;
        }
    }
    if (n > 1) printf("IMPOSSIBLE\n");
    else printf("%lld\n",sum);
    return 0;
}
