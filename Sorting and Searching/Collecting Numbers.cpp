#include <bits/stdc++.h>
using namespace std;

/*
La lógica es sencilla, se tiene un cojunto de números, y se van leyendo, si en
el conjunto ya está el número anterior al número leído entonces se borra el anterior
y se deja el leído. Si no está, entonces se aumenta en uno el contador.
*/

int main() {
    int n,cont=0,x;
    scanf("%d",&n);
    set<int> num;
    for (int i=0;i<n;i++) {
        scanf("%d",&x);
        set<int>::iterator it = num.lower_bound(x);
        if (num.size() == 0 || it == num.begin() || *prev(it) != x-1) {
            cont++;
        }
        else {
            num.erase(prev(it));
        }
        num.insert(x);
    }
    printf("%d\n",cont);
    return 0;
}
