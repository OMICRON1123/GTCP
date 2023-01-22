#include <bits/stdc++.h>
using namespace std;

/*
Se hace búsqueda binaria sobre la respuesta, para ello se fija una suma y se observa
si esta suma puede ser la máxima, para ello se ve si se puede dividir el arreglo
de tal manera que lo máximo sea la suma propuesta y la cantidad de intervalos
no supere la que nos dieron. Si la cantidad de intervalos es mayor entonces se hace
lo = suma + 1 ya que se sabe que la suma tendrá que ser mayor para que la cantidad
de intervalos disminuya, mientras que si sí se puede hacer entonces tenemos hi = mid.
*/

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    vector<long long> x(n),s(n+1);
    for (int i=0;i<n;i++) {
        scanf("%lld",&x[i]);
        s[i+1] = s[i] + x[i];
    }
    long long lo = 0,hi = s[n];
    while (lo < hi) {
        long long mid = (lo+hi)/2,aux = 0;
        int cont = 0;
        while (aux < s[n]) {
            auto it = prev(upper_bound(s.begin(),s.end(),aux+mid));
            if (*it == aux) {
                cont = k+1;
                break;
            }
            aux = *it;
            cont++;
        }
        if (cont > k) {
            lo = mid+1;
        }
        else {
            hi = mid;
        }
    }
    printf("%lld\n",lo);
    return 0;
}
