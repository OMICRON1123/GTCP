#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,last,init;
    scanf("%d",&n);
    vector<tuple<int,int,int> > range(n);
    vector<bool> contains(n),iscontained(n);
    for (int i=0;i<n;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        range[i] = make_tuple(x,y,i);
    }
    sort(range.begin(),range.end(),[](tuple<int,int,int> x,tuple<int,int,int> y) {
        if (get<1>(x) == get<1>(y)) return get<0>(x) > get<0>(y);
        return get<1>(x) < get<1>(y);
        });
    init = get<0>(range[0]);
    contains[get<2>(range[0])] = 0;
    for (int i=1;i<n;i++) {
        if (get<0>(range[i]) <= init) {
            contains[get<2>(range[i])] = 1;
        }
        else {
            init = get<0>(range[i]);
        }
    }
    sort(range.begin(),range.end(),[](tuple<int,int,int> x,tuple<int,int,int> y) {
        if (get<0>(x) == get<0>(y)) return get<1>(x) > get<1>(y);
        return get<0>(x) < get<0>(y);
        });
    last = get<1>(range[0]);
    iscontained[get<2>(range[0])] = 0;
    for (int i=1;i<n;i++) {
        if (get<1>(range[i]) <= last) {
            iscontained[get<2>(range[i])] = 1;
        }
        else {
            last = get<1>(range[i]);
        }
    }
    for (int i=0;i<n-1;i++)
        printf(contains[i] ? "1 " : "0 ");
    printf(contains[n-1] ? "1\n" : "0\n");
    for (int i=0;i<n-1;i++)
        printf(iscontained[i] ? "1 ": "0 ");
    printf(iscontained[n-1] ? "1\n" : "0\n");
    return 0;
}
