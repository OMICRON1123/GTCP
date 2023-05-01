#include <bits/stdc++.h>
using namespace std;

/*
Usar un Binary Indexed Tree con el arreglo de diferencias consecutivas ya que el
valor de la posición k equivale a sumar los elementos de este arreglo desde el primero
hasta el de la posición k.
*/

class FenwickTree;

class FenwickTree{
private:
    int sz;
    vector<long long> ft;

public:
    FenwickTree(vector<int> x) {
        sz = x.size();
        vector<long long> pre(sz+1);
        ft = vector<long long>(sz+1);
        for (int i=1;i<=sz;i++) {
            pre[i] = x[i-1]+pre[i-1];
            int k = i&-i;
            ft[i] = pre[i]-pre[i-k];
        }
    }

    long long query(int idx) {
        long long S = 0;
        while (idx > 0) {
            S += ft[idx];
            idx -= idx&-idx;
        }
        return S;
    }

    void update(int val,int loc) {
        while (loc <= sz) {
            ft[loc] += val;
            loc += loc&-loc;
        }
    }
};

int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    vector<int> x(n),sub(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&x[i]);
    }
    sub[0] = x[0];
    for (int i=1;i<n;i++) {
        sub[i] = x[i]-x[i-1];
    }
    FenwickTree tree = FenwickTree(sub);
    while (q--) {
        int type;
        scanf("%d",&type);
        if (type == 1) {
            int a,b,u;
            scanf("%d%d%d",&a,&b,&u);
            tree.update(u,a);
            if (b<n) tree.update(-u,b+1);
        }
        else {
            int k;
            scanf("%d",&k);
            printf("%lld\n",tree.query(k));
        }
    }
    return 0;
}
