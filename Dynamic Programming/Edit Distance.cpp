#include <bits/stdc++.h>
using namespace std;

/*
En este ejercicio se puede ver como una matriz dp[i][j] va a representar el costo mínimo
de volver iguales el primer string hasta la posición i con el segundo string hasta
la posición j. dp[0][0] = 0 ya que este representaría el caso de dos strings ambos
de longitud 0 y dp[i][0] = i así como dp[0][i] = i ya que el costo de convertir
un string de longitud i en longitud 0 es de i ya que se requieren borrar todas las
letras para el resto de casos se cumple que
dp[i][j] = min(dp[i][j-1]+1,dp[i-1][j]+1,dp[i-1][j-1]) para el caso en que la letra
de la posición i del primer string y la letra de la posición j del segundo string
sean diferentes. En caso de que sean igulaes la relación de modifica a
dp[i][j] = min(dp[i][j-1]+1,dp[i-1][j]+1,dp[i-1][j-1])
Esta es la relación debido a que dp[i][j-1]+1 sería el costo de eliminar la letra de la posición j
del segundo string lo cual cuesta uno y luego igualar el string de longitud j-1
con el string de longitud i, dp[i-1][j]+1 representa el costo de eliminar la letra de
la posición i del primer string lo cual cuesta uno y luego igualar el string de longitud
i-1 con el string de longitud j finalmente dp[i-1][j-1]+1 es el costo de remplazar
la letra de la posición i del primer string por la letra de la posición j o vice versa
y después igualar el string de longitud i-1 con el de longitud j-1 en caso de que
la letra de la posición i y la posición j sean iguales no es necesario remplazar y por
ello se toma dp[i-1][j-1] solamente, la respuesta al ejercicio queda en la
casilla inferior derecha de la matriz en la cual ya se han recorrido ambos strings
completamente, la matriz se puede llenar ya sea por filas o columnas y da lo mismo.
Finalmente cabe recalcar que el proceso de llenado de matriz es muy costoso en espacio
de memoria debido a que la matriz puede llegar a ser de 2x10^7 es por ello que se
optimiza la memoria remplazando la matriz por dos arreglos que van representando
la fila actual de la matriz y la fila anterior que son las únicas necesarias.
*/

int main() {
    bool ok = 0;
    string s1,s2;
    cin>>s1>>s2;
    if (s1.size() < s2.size()) {
        string aux = s1;
        s1 = s2;
        s2 = aux;
    }
    vector<int> dp1(s1.size()+1),dp2(s1.size()+1);
    for (int i=0;i<dp1.size();i++) {
        dp1[i] = i;
    }
    for (int i=1;i<=s2.size();i++) {
        for (int j=1;j<=s1.size();j++) {
            if (!ok) {
                if (j == 1) {
                    dp2[0] = dp1[0]+1;
                }
                if (s1[j-1] == s2[i-1]) {
                    dp2[j] = min(dp2[j-1]+1,min(dp1[j]+1,dp1[j-1]));
                }
                else {
                    dp2[j] = min(dp2[j-1]+1,min(dp1[j]+1,dp1[j-1]+1));
                }
            }
            else {
                if (j == 1) {
                    dp1[0] = dp2[0]+1;
                }
                if (s1[j-1] == s2[i-1]) {
                    dp1[j] = min(dp1[j-1]+1,min(dp2[j]+1,dp2[j-1]));
                }
                else {
                    dp1[j] = min(dp1[j-1]+1,min(dp2[j]+1,dp2[j-1]+1));
                }
            }
        }
        ok = !ok;
    }
    if (ok) {
        printf("%d\n",dp2[dp2.size()-1]);
    }
    else {
        printf("%d\n",dp1[dp1.size()-1]);
    }
    return 0;
}
