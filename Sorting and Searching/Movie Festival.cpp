#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,idx = 1,cont = 1,fin;
    scanf("%d",&n);
    vector<pair<int,int> > movie(n);
    for (int i=0;i<n;i++) {
        scanf("%d%d",&movie[i].first,&movie[i].second);
    }
    sort(movie.begin(),movie.end(),[](pair<int,int> x, pair<int,int> y) {
            if (x.second == y.second) return x.first < y.first;
            return x.second < y.second;
         });
    fin = movie[0].second;
    while (idx < n) {
        if (movie[idx].first >= fin) {
            cont++;
            fin = movie[idx].second;
        }
        idx++;
    }
    printf("%d\n",cont);
    return 0;
}
