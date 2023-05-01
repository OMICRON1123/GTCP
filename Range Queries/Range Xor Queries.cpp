#include <bits/stdc++.h>
using namespace std;

class SegmentTree;

class SegmentTree{
private:
    int sz;
    vector<int> x,st;

    void build(int l,int r,int pos) {
        if (l == r) {
            st[pos] = x[l];
            return;
        }
        build(l,(l+r)/2,2*pos);
        build((l+r)/2+1,r,2*pos+1);
        st[pos] = st[2*pos]^st[2*pos+1];
    }

    int query(int a,int b,int l,int r,int pos) {
        if (r < a || l > b) return 0;
        if (l >= a && r <= b) return st[pos];
        return query(a,b,l,(l+r)/2,2*pos)^query(a,b,(l+r)/2+1,r,2*pos+1);
    }

public:
    SegmentTree(vector<int> x) {
        sz = x.size();
        this->x = x;
        st = vector<int>(4*sz);
        build(0,sz-1,1);
    }

    int query(int a,int b) {
        return query(a,b,0,sz-1,1);
    }
};

int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    vector<int> x(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&x[i]);
    }
    SegmentTree tree = SegmentTree(x);
    while(q--) {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",tree.query(a-1,b-1));
    }
    return 0;
}
