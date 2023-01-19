#include <bits/stdc++.h>
using namespace std;

/*
Sencillamente se van calculando las sumas de los subarray, si la suma ya supera
el número deseado entonces se le resta los números del principio hasta que sea menor
o igual y se aumenta en uno el contador si la suma es igual al número deseado.
*/

int main() {
    int n,x,s = 0,idx = 0,cont = 0;
    scanf("%d%d",&n,&x);
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++) {
        s += a[i];
        while (s > x) s -= a[idx++];
        if (s == x) cont++;
    }
    printf("%d\n",cont);
    return 0;
}
