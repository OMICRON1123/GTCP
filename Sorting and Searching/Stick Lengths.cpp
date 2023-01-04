#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long best,cost = 0,small = 0,great;
    scanf("%d",&n);
    vector<long long> p(n);
    vector<pair<long long,long long> > dis;
    for (int i=0;i<n;i++) {
        scanf("%lld",&p[i]);
    }
    sort(p.begin(),p.end());
    dis.push_back(make_pair(p[0],1));
    for (int i=1;i<n;i++) {
        if (p[i] == dis[dis.size()-1].first) {
            dis[dis.size()-1].second++;
        }
        else {
            dis.push_back(make_pair(p[i],1));
        }
        cost += p[i]-p[0];
    }
    best = cost;
    small = dis[0].second;
    great = n - dis[0].second;
    for (int i=1;i<dis.size();i++) {
        long long curr = dis[i].first-dis[i-1].first;
        cost = cost + small*curr-great*curr;
        small += dis[i].second;
        great -= dis[i].second;
        best = cost < best ? cost : best;
    }
    printf("%lld\n",best);
    return 0;
}
