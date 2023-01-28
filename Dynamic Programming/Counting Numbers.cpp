#include <bits/stdc++.h>
using namespace std;

/*
Dado un cierto n�mero x para hallar la cantidad de n�meros distintos entre 1 y x
se convierte x en un vector que contiene sus d�gitos, sea d[i] el d�gito en la posici�n
i donde d[0] representa el d�gito en las unidades. En primer lugar se analiza
d[0] si d[0] es mayor o igual que d[1] entonces el total se aumenta en d[0]
si por otro lado es menor entonces el total se aumenta en d[0]+1.
Ahora si se est� en la posici�n i y se cumple d[i] > d[i+1] entonces total se aumenta
en (d[i]-1)*(9^(i-1)), si es menor entonces total se aumenta en d[i]*(9^(i-1)).
Si se est� en la �ltima posici�n entonces total se aumenta en d[i]*(9^(i-1)).
Despu�s de esto si el n�mero ten�a n d�gitos en total entonces a total se le suma
total += 9+9^2+9^3+...+9^n-2. Si n es menor o igual que dos no se le suma nada.
Este algoritmo solo funciona si el n�mero no tiene n�meros iguales adyacente excepto
posiblemente d[0] y d[1], si se tiene d[i] = d[i+1] para i >= 1 entonces se le resta
uno a d[i], todo los n�meros anteriores, es d[j] tal que j < i se transforman en
d[j] =9, si d[i] = 0 entonces se hace d[i] = 8 y todos los n�meros anteriores se
transforman en 9 as� como todos los posteriores que sean 0 tambi�n se transforman en
9 este proceso se repite con cada n�mero hasta que no hayan n�meros adyacentes iguales
excepto posiblemente el d[0] y d[1], si hay ceros al final del vector se procede a
eliminarlos. Este algoritmo se basa en las permutaciones con repetici�n ya que
si un d�gito es cierto n�mero el que le sigue puede ser 9 d�gitos distintos ya que en
total hay 10 d�gitos pero uno ya est� ocupado. Al principio el algoritmo analiza
cu�ntos n�meros hay que tienen sus n primeros d�gitos en este caso los �ltimos del
arreglo iguales al n�mero original, la sumatoria de potencias de 9 al final
corresponde a lo que pasar�a si los n primeros d�gitos fueran 0 y cu�ntos n�meros
se podr�an formar de esta manera.
*/

vector<int> digits(long long x) {
    vector<int> vec;
    while (x > 0) {
        vec.push_back(x%10);
        x /= 10;
    }
    return vec;
}

int main() {
    long long a,b,tot1 = 0,tot2 = 0,prod = 1;
    scanf("%lld %lld",&a,&b);
    vector<int> dig1 = digits(a-1),dig2 = digits(b);
    for (int i=0;i<dig1.size();i++) {
        for (int j=1;j<dig1.size()-1;j++) {
            if (dig1[j] == dig1[j+1] && dig1[j] != 0) {
                dig1[j]--;
                int t = j-1;
                while (t >= 0) {
                    dig1[t--] = 9;
                }
            }
            else if (dig1[j] == dig1[j+1]) {
                dig1[j] = 8;
                int k = j+1,t=j-1;
                while (t >= 0) {
                    dig1[t--] = 9;
                }
                while (dig1[k] == 0) {
                    dig1[k++] = 9;
                }
                dig1[k]--;
            }
        }
    }
    while (dig1.size() >  0 && dig1[dig1.size()-1] == 0) {
        dig1.pop_back();
    }
    for (int i=0;i<dig2.size();i++) {
        for (int j=1;j<dig2.size()-1;j++) {
            if (dig2[j] == dig2[j+1] && dig2[j] != 0) {
                dig2[j]--;
                int t = j-1;
                while (t >= 0) {
                    dig2[t--] = 9;
                }
            }
            else if (dig2[j] == dig2[j+1]) {
                dig2[j] = 8;
                int k = j+1,t=j-1;
                while (t >= 0) {
                    dig2[t--] = 9;
                }
                while (dig2[k] == 0) {
                    dig2[k++] = 9;
                }
                dig2[k]--;
            }
        }
    }
    while (dig2.size() >  0 && dig2[dig2.size()-1] == 0) {
        dig2.pop_back();
    }
    for (int i=0;i<dig1.size();i++) {
        if (i == dig1.size()-1) {
            tot1 += prod*dig1[i];
        }
        else if (i == 0) {
            tot1 += dig1[i] >= dig1[i+1] ? prod*dig1[i]: prod*(dig1[i]+1);
        }
        else {
            tot1 += dig1[i] > dig1[i+1] ? prod*(dig1[i]-1) : prod*dig1[i];
        }
        prod *= 9;
        if (i < (int) dig1.size()-2) {
            tot1 += prod;
        }
    }
    if (a == 0)
        tot1 = -1;
    prod = 1;
    for (int i=0;i<dig2.size();i++) {
        if (i == dig2.size()-1) {
            tot2 += prod*dig2[i];
        }
        else if (i == 0) {
            tot2 += dig2[i] >= dig2[i+1] ? prod*dig2[i]: prod*(dig2[i]+1);
        }
        else {
            tot2 += dig2[i] > dig2[i+1] ? prod*(dig2[i]-1) : prod*dig2[i];
        }
        prod *= 9;
        if (i < (int) dig2.size()-2) {
            tot2 += prod;
        }
    }
    printf("%lld\n",tot2-tot1);
    return 0;
}
