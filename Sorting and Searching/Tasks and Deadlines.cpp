#include <bits/stdc++.h>
using namespace std;

/*
Hay que tener en cuenta que primero se deben hacer las tareas con menor duración
ya que si d[i] es la fecha límite de la i-ésima tarea y a[i] es la duración
de la i-ésima tarea y las procesamos en ese orden la recompensa R viene dada por
R = d[1]-a[1]+(d[2]-a[1]-a[2])+...+(d[n]-a[1]-a[2]-...-a[n])
y reagrupando tenemos que
R = sum(i=1,n){d[i]}-sum(i=1,n){(n-i+1)*a[i])} por lo tanto lo mejor es tener
el conjunto a[i] ordenado de menor a mayor para con eso todos los términos
se hacen lo menor posible.
*/

int main() {
    long long n,tot = 0,dur = 0;
    scanf("%lld",&n);
    vector<pair<long long,long long> > task(n);
    for (int i=0;i<n;i++) {
        scanf("%lld%lld",&task[i].first,&task[i].second);
    }
    sort(task.begin(),task.end());
    for (int i=0;i<n;i++) {
        dur += task[i].first;
        tot += task[i].second - dur;
    }
    printf("%lld\n",tot);
    return 0;
}
