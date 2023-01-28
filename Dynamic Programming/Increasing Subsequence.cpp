#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se guardan dos mapas, el mapa num[i] indica en qu� n�mero
termina la secuencia de longitud i, y el mapa seq[i] indica qu� longitud tiene
la secuencia que termina en el n�mero i. Digamos que se va a agregar un nuevo n�mero
j entonces se busca en el mapa seq qu� secuencia termina en un n�mero menor a este.
Si no existe ninguna es porque j es el menor de los n�meros que se han analizado
y entonces se crea seq[j] = 1, adem�s num[1] = j debido a q entre menor sea el n�mero
final de una secuencia m�s n�meros se podr�an agregar posteriormente,
no obstante antes de hacer num[1] = j se tiene que eliminar de seq el valor anterior
de num[1] ya que el valor anterior ya no tendr�a representaci�n alguna. Entonces ser�a
seq[j] = 1;
seq.erase(num[1])
num[1] = j
Cuando s� existe una secuencia q termina en un n�mero menor entonces se podr�a crear
una nueva secuencia de longitud 1 mayor a esta con el n�mero, si no exist�a
una secuencia de esta longitud se a�ade a num y a seq pero si s� exist�a se compara
cu�l de las dos secuencias, la anterior o la nueva, termina en un n�mero menor.
Si la nueva es la que termina en un n�mero menor entonces se hace seq.erase(num[1]);
seq[j] = ant+1; num[ant+1] = j, donde ant+1 representa la longitud de la nueva
secuencia.
Con esto ya se resuelve el ejercicio cuando se hallan analizado todos los j del arreglo
la respuesta ser�a la mayor llave del mapa num.
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
