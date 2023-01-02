#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,t;
    scanf("%d%d",&n,&m);
    set<int> h;
    map<int,int> rep;
    for (int i=0;i<n;i++) {
        scanf("%d",&t);
        h.insert(t);
        if (rep.find(t) == rep.end()) {
            rep.insert({t,1});
        }
        else {
            rep[t]++;
        }
    }
    for (int i=0;i<m;i++) {
        scanf("%d",&t);
        set<int>::iterator it = h.upper_bound(t);
        if (it == h.begin()) {
            printf("-1\n");
        }
        else {
            it = prev(it);
            int aux = *it;
            printf("%d\n",aux);
            h.erase(it);
            if (--rep[aux] > 0) {
                h.insert(aux);
            }
        }
    }
    return 0;
}
