#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,n,p;
    set<int> light;
    multiset<int> len;
    scanf("%d%d",&x,&n);
    light.insert(0);
    light.insert(x);
    len.insert(x);
    for (int i=0;i<n;i++) {
        scanf("%d",&p);
        auto it = light.upper_bound(p);
        int b = *it, a = *prev(it);
        len.insert(p-a);
        len.insert(b-p);
        len.erase(len.find(b-a));
        light.insert(p);
        printf(i == n-1 ? "%d\n":"%d ",*prev(len.end()));
    }
    return 0;
}
