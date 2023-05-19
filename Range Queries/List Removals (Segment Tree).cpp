#include <bits/stdc++.h>
using namespace std;

/*
Usar un segment tree, el nodo izquierdo guarda cuántos elementos hay en el
segmento izquierdo mientras el derecho cuántos hay en el segmento derechos.
Con base en esta información se puede saber a qué posición actual corresponde
la posición digitada.
*/

class SegmentTree;

class SegmentTree{
private:
    int sz;
    vector<int> st;

    void build(int l,int r,int pos) {
        if (l == r) {
            st[pos] = 1;
            return;
        }
        build(l,(l+r)/2,2*pos);
        build((l+r)/2+1,r,2*pos+1);
        st[pos] = st[2*pos]+st[2*pos+1];
    }

    int query(int num,int l,int r,int pos) {
        if (l == r) return l;
        if (num <= st[2*pos]) return query(num,l,(l+r)/2,2*pos);
        return query(num-st[2*pos],(l+r)/2+1,r,2*pos+1);
    }

    void update(int loc,int l,int r,int pos) {
        if (l == r) {
            st[pos] = 0;
            return;
        }
        if (loc <= (l+r)/2) update(loc,l,(l+r)/2,2*pos);
        else update(loc,(l+r)/2+1,r,2*pos+1);
        st[pos] = st[2*pos]+st[2*pos+1];
    }

public:
    SegmentTree(int n) {
        sz = n;
        st = vector<int>(4*sz);
        build(0,sz-1,1);
    }

    int query(int num) {
        int ans = query(num,0,sz-1,1);
        update(ans,0,sz-1,1);
        return ans;
    }
};

int main() {
    int n;
    scanf("%d",&n);
    vector<int> x(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&x[i]);
    }
    SegmentTree tree = SegmentTree(n);
    while (n--) {
        int p;
        scanf("%d",&p);
        p = tree.query(p);
        printf(n ? "%d ":"%d\n",x[p]);
    }
    return 0;
}
