#include <bits/stdc++.h>
using namespace std;

/*
Se ordena el vector.
La lógica es tener en cuenta que la longitud óptima a la que se deben convertir
siempre será un valor de las longitudes ya dadas debido a que si consideramos
una función F(x) que arroja el costo total para cierta longitud x que cumple que
p[i] <= x < p[i+1] es decir que x está entre dos valores de longitudes, en este
intervalo simpre habrá un número constante de valores p[i] menores o iguales a x,
asumamos que el número de valores menores o iguales es m entonces
F(x)=(x-p[1])+...+(x-p[m])+(p[m+1]-x)+...+(p[n]-x)
Reagrupando los términos tenemos
F(x) = (p[m+1]+...p[n])-(p[1]+...+p[m])+m*x-(n-m)*x
Como p[i] <= x < p[i+1] m es constante entonces (p[m+1]+...+p[n])-(p[1]+...+p[m]) es
constante C y F(x) se puede escribir como
F(x) = C+(2*m-n)*x
Y debido a que esta es una función lineal en x su valor máximo siempre estará en
alguno de los dos extremos, es decir, en x=p[i] o en x=p[i+1]

Ahora tomando en cuenta lo anterior solo hay que calcular los costos para convertir
todos los palos en cada longitud ya dada. Sin embargo, para hacerlo eficiente es
mejor llevar un control de cuántos palos tienen longitud menor a otra y de esta
manera solo modificar el costo de acuerdo a cuántos palos menores se agregan.
Para esto es bueno saber q si tengo n palos menores o iguales y corro la longitud
x a la derecha el costo aumenta n*x y si tengo M palos mayores y corro
x a la derecha el costo disminuy en M*x siempre y cuando se vaya analizando en
longitudes consecutivas
*/

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
