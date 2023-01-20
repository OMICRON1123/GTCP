#include <bits/stdc++.h>
using namespace std;

/*
Para este ejercicio se tiene que tener en cuenta que si un subarreglo que va desde
i hasta j es divisible por n entonces es porque los subarreglos que van desde 0 hasta i
y desde 0 hasta j tienen el mismo residuo con respecto a n con esto s[j]-s[i] es divisible por n
teniendo en cuenta esto se tiene que almacenar cuántos subarreglos desde 0 han tenido
cierto residuo y esta será la cantidad en la que aumenta el contador cuando la nueva suma
hasta la nueva posición tiene este residuo.
*/

int main() {
    int n,a;
    scanf("%d",&n);
    long long s = 0,cont = 0;
    vector<int> res(n);
    res[0] = 1;
    for (int i=0;i<n;i++) {
        scanf("%d",&a);
        s += a;
        cont += res[(s%n+n)%n];
        res[(s%n+n)%n]++;
    }
    printf("%lld\n",cont);
    return 0;
}
