#include <bits/stdc++.h>
using namespace std;

/*
La l�gica es sencilla, se tiene un cojunto de n�meros, y se van leyendo, si en
el conjunto ya est� el n�mero anterior al n�mero le�do entonces se borra el anterior
y se deja el le�do. Si no est�, entonces se aumenta en uno el contador.
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
