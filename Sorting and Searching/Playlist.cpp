#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se tiene que mantener un mapa que indica la última posición de
una canción. A medida que se recorre el playlist se va a mantener una variable que
indica desde qué posición se comienza a contar el playlist actual, si al momento
de agregar una canción esta nunca había aparecido o la última vez que apareció fue
antes de la posición desde que se comienza a contar entonces la posición se
mantiene igual y la última posición de la canción con esa id se modifica a la acutal
Por otro lado si la canción aparece después de la posición donde se comienza a
contar esta posición se modifica y se igual a la posición donde ocurre la repetición
más 1. Con esto se asegura que desde la posición donde se comienza a contar hasta
la actual no hay repetidos. Por cada número del playlist se ve si la cantidad de
cancions (posicionActual-posicionInicial+1) es mayor y si es así se actualiza
la variable best.
*/

int main() {
    int n,k,pos = 0, best = 0;
    scanf("%d",&n);
    map<int,int> song;
    for (int i=0;i<n;i++) {
        scanf("%d",&k);
        if (song.find(k) == song.end()) {
            song.insert({k,i});
            best = i-pos+1 > best ? i-pos+1 : best;
        }
        else if (song[k] >= pos){
            pos = song[k]+1;
            song[k] = i;
        }
        else {
            best = i-pos+1 > best ? i-pos+1 : best;
            song[k] = i;
        }
    }
    printf("%d\n",best);
    return 0;
}
