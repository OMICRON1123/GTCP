#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_multiset;

int main() {
    int n;
    indexed_multiset init,last;
    scanf("%d",&n);
    vector<int> contains(n),iscontained(n);
    vector<tuple<int,int,int> > range(n);
    for (int i=0;i<n;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        range[i] = make_tuple(x,y,i);
    }
    sort(range.begin(),range.end(),[](tuple<int,int,int> x,tuple<int,int,int> y) {
        if (get<1>(x) == get<1>(y)) return get<0>(x) > get<0>(y);
        return get<1>(x) < get<1>(y);
    });
    contains[get<2>(range[0])] = 0;
    init.insert(get<0>(range[0]));
    for (int i=1;i<n;i++) {
        contains[get<2>(range[i])] = i - init.order_of_key(get<0>(range[i]));
        init.insert(get<0>(range[i]));
    }
    sort(range.begin(),range.end(),[](tuple<int,int,int> x,tuple<int,int,int> y) {
        if (get<0>(x) == get<0>(y)) return get<1>(x) > get<1>(y);
        return get<0>(x) < get<0>(y);
    });
    iscontained[get<2>(range[0])] = 0;
    last.insert(get<1>(range[0]));
    for (int i=1;i<n;i++) {
        iscontained[get<2>(range[i])] = i - last.order_of_key(get<1>(range[i]));
        last.insert(get<1>(range[i]));
    }
    for (int i=0;i<n;i++)
        printf(i == n-1 ? "%d\n":"%d ",contains[i]);
    for (int i=0;i<n;i++)
        printf(i == n-1 ? "%d\n":"%d ",iscontained[i]);
    return 0;
}
