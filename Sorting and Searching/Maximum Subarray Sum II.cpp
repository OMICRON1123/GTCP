#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio guardamos las sumas de los subarreglos desde la primera posición
hasta cierta posición. Comenzamos a recorrer el arreglo de sumas desde la posición a
y tengamos en cuenta que la posición 0 es 0. Entonces mantenemos un conjunto con las
sumas. En la posición a se añade la suma s[0] y en la posición i se añada la suma s[i-a]
ya que este sería el arreglo de longitud a que termina en i luego si el conjunto
de sumas tiene una cantidad mayor a b-a+1 esto quiere decir que el arreglo que
podríamos estar considerando podría tener longitud mayor que b, entonces en este caso
eliminamos la suma más antigua que se añadió al conjunto. De esta manera solo estamos
teniendo en cuenta subarreglos de longitud entre a y b. Finalmente la mejor suma
que se puede tener de un subarreglo que termina en i será s[i] menos el primer elemento
del set que es la menor de las sumas anteriores y se compara si esta suma es mayor
de toda la historia y si es así pues se guarda como la mejor.
*/

int main() {
    int n,a,b,len = 0,idx = 0;
    long long best;
    scanf("%d%d%d",&n,&a,&b);
    vector<long long> s(n+1);
    multiset<long long> sums;
    for (int i=0;i<n;i++) {
        int x;
        scanf("%d",&x);
        s[i+1] = s[i] + x;
    }
    best = s[a];
    for (int i=a;i<=n;i++) {
        sums.insert(s[i-a]);
        if (sums.size() > b-a+1) {
            sums.erase(sums.find(s[idx++]));
        }
        long long nbest = s[i] - *sums.begin();
        best = nbest > best ? nbest : best;
    }
    printf("%lld\n",best);
    return 0;
}
