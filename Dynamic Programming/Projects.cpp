#include <bits/stdc++.h>
using namespace std;

/*
Este ejercicio es un knapsack en el cual toca optimizar el espacio,
para optimizar el espacio en vez de tomar un arreglo que vaya hasta 10^9 se organiza
un mapa al cual solo se le llenan los espacios del tiempo donde termina el proyecto
si un proyecto comienza en a y termina en b entonces dp[b] es la máximo entre
ir a este proyecto o no ir es decir el máximo entre dp[a-1]+p y dp[b], hay que tener
en cuenta q como es un mapa dp[a-1] podría no existir, en dicho caso
se toma el número más cercano a a-1 que sea menor y exista en el mapa dp, similarmente
ocurre si dp[b] no existe.
*/

int main() {
    int n;
    scanf("%d",&n);
    vector<tuple<int,int,int> > proj(n);
    map<int,long long> dp;
    dp.insert({0,0});
    for (int i=0;i<n;i++) {
        int a,b,p;
        scanf("%d%d%d",&a,&b,&p);
        proj[i] = make_tuple(b,a,p);
    }
    sort(proj.begin(),proj.end());
    for (int i=0;i<n;i++) {
        auto it1 = prev(dp.lower_bound(get<1>(proj[i])));
        auto it2 = prev(dp.upper_bound(get<0>(proj[i])));
        if (dp.find(get<0>(proj[i])) == dp.end())
            dp.insert({get<0>(proj[i]),max(it1->second + get<2>(proj[i]),it2->second)});
        else
            dp[get<0>(proj[i])] = max(it1->second +get<2>(proj[i]),it2->second);
    }
    printf("%lld\n",prev(dp.end())->second);
    return 0;
}
