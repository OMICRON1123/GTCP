#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se tiene que mantener un mapa que indica la �ltima posici�n de
una canci�n. A medida que se recorre el playlist se va a mantener una variable que
indica desde qu� posici�n se comienza a contar el playlist actual, si al momento
de agregar una canci�n esta nunca hab�a aparecido o la �ltima vez que apareci� fue
antes de la posici�n desde que se comienza a contar entonces la posici�n se
mantiene igual y la �ltima posici�n de la canci�n con esa id se modifica a la acutal
Por otro lado si la canci�n aparece despu�s de la posici�n donde se comienza a
contar esta posici�n se modifica y se igual a la posici�n donde ocurre la repetici�n
m�s 1. Con esto se asegura que desde la posici�n donde se comienza a contar hasta
la actual no hay repetidos. Por cada n�mero del playlist se ve si la cantidad de
cancions (posicionActual-posicionInicial+1) es mayor y si es as� se actualiza
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
