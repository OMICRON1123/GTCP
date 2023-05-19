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
        st[pos] = max(st[2*pos],st[2*pos+1]);
    }

    int query(int num,int l,int r,int pos) {
        if (l == r) return l;
        if (st[2*pos] >= num) return query(num,l,(l+r)/2,2*pos);
        return query(num,(l+r)/2+1,r,2*pos+1);
    }

    void update(int val,int loc,int l,int r,int pos) {
        if (l == r) {
            x[l] = val;
            st[pos] = val;
            return;
        }
        if (loc <= (l+r)/2) update(val,loc,l,(l+r)/2,2*pos);
        else update(val,loc,(l+r)/2+1,r,2*pos+1);
        st[pos] = max(st[2*pos],st[2*pos+1]);
    }

public:
    SegmentTree(vector<int> x) {
        sz = x.size();
        this->x = x;
        st = vector<int>(4*sz);
        build(0,sz-1,1);
    }

    int query(int num) {
        if (st[1] < num) return 0;
        int ans = query(num,0,sz-1,1);
        update(x[ans]-num,ans,0,sz-1,1);
        return ans+1;
    }
};

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> h(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&h[i]);
    }
    SegmentTree tree = SegmentTree(h);
    while (m--) {
        int r;
        scanf("%d",&r);
        printf("%d\n",tree.query(r));
    }
    return 0;
}
