#include <bits/stdc++.h>
using namespace std;

/*
Usar un segment tree para calcular las respuestas.
*/

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
        build(l,(r+l)/2,2*pos);
        build((r+l)/2+1,r,2*pos+1);
        st[pos] = min(st[2*pos],st[2*pos+1]);
    }

    int query(int a,int b,int l,int r,int pos) {
        if (r < a || l > b) return 1e9+1;
        if (l >= a && r <= b) return st[pos];
        return min(query(a,b,l,(r+l)/2,2*pos),query(a,b,(r+l)/2+1,r,2*pos+1));
    }

    void update(int val,int loc,int l,int r,int pos) {
        if (l == r) {
            st[pos] = val;
            return;
        }
        if (loc <= (r+l)/2) update(val,loc,l,(r+l)/2,2*pos);
        else update(val,loc,(r+l)/2+1,r,2*pos+1);
        st[pos] = min(st[2*pos],st[2*pos+1]);
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

    void update(int val,int loc) {
        update(val,loc,0,sz-1,1);
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
    while (q--) {
        int type;
        scanf("%d",&type);
        if (type == 1) {
            int k,u;
            scanf("%d%d",&k,&u);
            tree.update(u,k-1);
        }
        else {
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",tree.query(a-1,b-1));
        }
    }
    return 0;
}
