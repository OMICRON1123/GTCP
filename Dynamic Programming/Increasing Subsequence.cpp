#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se guardan dos mapas, el mapa num[i] indica en qué número
termina la secuencia de longitud i, y el mapa seq[i] indica qué longitud tiene
la secuencia que termina en el número i. Digamos que se va a agregar un nuevo número
j entonces se busca en el mapa seq qué secuencia termina en un número menor a este.
Si no existe ninguna es porque j es el menor de los números que se han analizado
y entonces se crea seq[j] = 1, además num[1] = j debido a q entre menor sea el número
final de una secuencia más números se podrían agregar posteriormente,
no obstante antes de hacer num[1] = j se tiene que eliminar de seq el valor anterior
de num[1] ya que el valor anterior ya no tendría representación alguna. Entonces sería
seq[j] = 1;
seq.erase(num[1])
num[1] = j
Cuando sí existe una secuencia q termina en un número menor entonces se podría crear
una nueva secuencia de longitud 1 mayor a esta con el número, si no existía
una secuencia de esta longitud se añade a num y a seq pero si sí existía se compara
cuál de las dos secuencias, la anterior o la nueva, termina en un número menor.
Si la nueva es la que termina en un número menor entonces se hace seq.erase(num[1]);
seq[j] = ant+1; num[ant+1] = j, donde ant+1 representa la longitud de la nueva
secuencia.
Con esto ya se resuelve el ejercicio cuando se hallan analizado todos los j del arreglo
la respuesta sería la mayor llave del mapa num.
*/

int main() {
    int n;
    scanf("%d",&n);
    map<int,int> seq,num;
    vector<int> x(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&x[i]);
    }
    seq.insert({x[0],1});
    num.insert({1,x[0]});
    for (int i=1;i<n;i++) {
        map<int,int>::iterator it = seq.lower_bound(x[i]);
        if (it == seq.begin()) {
            if (seq.find(x[i]) == seq.end()) {
                seq.insert({x[i],1});
            }
            if (num[1] > x[i]) {
                seq.erase(seq.find(num[1]));
                num[1] = x[i];
            }
        }
        else {
            it--;
            if (num.find(it->second+1) == num.end()) {
                num.insert({it->second+1,x[i]});
                seq.insert({x[i],it->second+1});
            }
            else if (num[it->second+1] > x[i]){
                seq.erase(seq.find(num[it->second+1]));
                num[it->second+1] = x[i];
                seq.insert({x[i],it->second+1});
            }
        }
    }
    printf("%d\n",prev(num.end())->first);
    return 0;
}
