#include <bits/stdc++.h>
using namespace std;

/*
Usar un Binary Indexed Tree para calcular la respuesta
*/

class FenwickTree;

class FenwickTree{
private:
    int sz;
    vector<long long> pre,ft;

    long long sum(int idx) {
        long long S = 0;
        while(idx > 0) {
            S += ft[idx];
            idx -= idx&-idx;
        }
        return S;
    }

public:
    FenwickTree(vector<int> x) {
        sz = x.size();
        pre = ft = vector<long long>(sz+1);
        for (int i=1;i<=sz;i++) {
            pre[i] = x[i-1]+pre[i-1];
            int k = i&-i;
            ft[i] = pre[i]-pre[i-k];
        }
    }

    long long query(int a,int b) {
        return sum(b)-sum(a-1);
    }

    void update(long long val,int loc) {
        while (loc <= sz) {
            ft[loc] += val;
            loc += loc&-loc;
        }
    }
};

int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    vector<int> x(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&x[i]);
    }
    FenwickTree tree = FenwickTree(x);
    while (q--) {
        int type;
        scanf("%d",&type);
        if (type == 1) {
            int k,u;
            scanf("%d%d",&k,&u);
            tree.update(u-x[k-1],k);
            x[k-1] = u;
        }
        else {
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%lld\n",tree.query(a,b));
        }
    }
    return 0;
}
