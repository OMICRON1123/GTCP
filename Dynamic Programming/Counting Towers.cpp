#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

/*
Este ejercicio se basa en una relaci�n recursiva en la que se guarda cu�ntas de las
torres terminan con una divisi�n en la cima y cu�ntas con un bloque compacto, sea a[n]
las torres que terminan con una divisi�n en la cima cuando la altura es n
y sea b[n] las torres q terminan con un bloque compacto. Entonces se cumple que
a[n+1] = 4*a[n]+b[n] y b[n+1] = a[n]+2*b[n] esto es debido a que cuando se agrega
el �ltimo bloque con una divisi�n y el anterior ya tiene un divisi�n hay en total 4
posibilidades nuevas mientras que cuando se agrega un bloque con divisi�n a uno sin divisi�n
solo hay una posibilidad de a�adirlo. Mientras que cuando le a�adimos un bloque sin divisi�n
a uno sin divisi�n hay dos posibilidades y si se le a�ade uno sin divisi�n a uno con divisi�n
solo hay una posibilidad. La respuesta para n es l�gicamente a[n]+b[n]
*/

int main() {
    int t,n;
    long long num0 = 1,num1 = 1;
    vector<long long> dp;
    dp.push_back(2);
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        while (n > dp.size()) {
            dp.push_back((5*num1+3*num0)%MOD);
            long long aux0 = num0, aux1 = num1;
            num0 = aux1+2*aux0;
            num1 = 4*aux1+aux0;
            num0 %= MOD;
            num1 %= MOD;
        }
        printf("%lld\n",dp[n-1]);
    }
    return 0;
}
