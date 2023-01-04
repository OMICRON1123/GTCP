#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,cont = 0,a,b;
    scanf("%d%d",&n,&m);
    vector<int> x(n);
    set<int> num;
    map<int,int> pos;
    for (int i=0;i<n;i++) {
        scanf("%d",&x[i]);
        pos[x[i]] = i+1;
        set<int>::iterator it = num.lower_bound(x[i]);
        if (num.size() == 0 || it == num.begin() || *prev(it) != x[i]-1) {
            cont++;
        }
        else {
            num.erase(prev(it));
        }
        num.insert(x[i]);
    }
    for (int i=0;i<m;i++) {
        scanf("%d%d",&a,&b);
        a--; b--;
        if (a > b) {
            int aux = b;
            b = a;
            a = aux;
        }
        if (x[a]-x[b] == 1) {
            cont--;
        }
        if (x[a]-x[b] == -1) {
            cont++;
        }
        if (pos[x[b]-1] < b+1 && pos[x[b]-1] > a+1) {
            cont++;
        }
        if (pos[x[b]+1] < b+1 && pos[x[b]+1] > a+1) {
            cont--;
        }
        if (pos[x[a]+1] < b+1 && pos[x[a]+1] > a+1) {
            cont++;
        }
        if (pos[x[a]-1] < b+1 && pos[x[a]-1] > a+1) {
            cont--;
        }
        pos[x[a]] = b+1;
        pos[x[b]] = a+1;
        int aux = x[a];
        x[a] = x[b];
        x[b] = aux;
        printf("%d\n",cont);
    }
    return 0;
}
