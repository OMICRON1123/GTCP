#include <bits/stdc++.h>
using namespace std;

/*
La explicaci�n a este ejercicio se encuentra bastante detallada en el libro
Guide To Competitive Programming en el cap�tulo de Programaci�n Din�mica.
En general se basa en recorrer todos los posibles subconjuntos y en cada cada uno
guardar cu�ntos viajes se hizo y el peso del �ltimo viaje. Luego en cada subconjunto
se observan los subconjuntos de este que solo difieren por un uno y se mira si el peso de la persona sumado
con el peso del �ltimo viaje es menor al peso maximo si es as� se tiene que la cantidad
de viajes es la misma que la anterior y el peso aumenta el peso de la persona, si por
otro lado es mayor entonces se tiene que la cantidad de viajes aumenta en 1 y el peso
ser� el peso de la �ltima persona, se observa para todos los subconjuntos cu�l es el
que minimiza la cantidad de viajes y estos son los valores que se dejan.
*/

int main() {
    int n,x;
    scanf("%d%d",&n,&x);
    vector<int> w(n);
    vector<pair<int,int> > dp(1<<n); //first = numero de veces, second = peso de la �ltima
    for (int i=0;i<n;i++) {
        scanf("%d",&w[i]);
    }
    dp[0] = {1,0};
    for (int i=1;i<(1<<n);i++) {
        dp[i] = {1e9+1,0};
        for (int j=0;j<n;j++) {
            if((1<<j)&i) {
                int idx = i^(1<<j);
                dp[i] = min(dp[i],dp[idx].second+w[j] > x ? make_pair(dp[idx].first+1,w[j]) : make_pair(dp[idx].first,dp[idx].second+w[j]));
            }
        }
    }
    printf("%d\n",dp[(1<<n)-1].first);
    return 0;
}
