#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    scanf("%d%d",&n,&x);
    vector<pair<int,int> > a(n);
    for (int i = 0;i<n;i++) {
        scanf("%d",&a[i].first);
        a[i].second = i+1;
    }
    sort(a.begin(),a.end());
    if (n == 1) {
        printf("IMPOSSIBLE\n");
    }
    else {
        for (int i = 0;i<n-1;i++) {
            auto it = lower_bound(a.begin()+i+1,a.end(),make_pair(x-a[i].first,0));
            if ((*it).first == x - a[i].first) {
                printf("%d %d\n",a[i].second,a[it-a.begin()].second);
                break;
            }
            else if (i == n-2) {
                printf("IMPOSSIBLE\n");
            }
        }
    }
    return 0;
}
