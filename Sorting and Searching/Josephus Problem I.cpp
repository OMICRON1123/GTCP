#include <bits/stdc++.h>
using namespace std;

/*
Se hace sencillamente la simulación con un set que almacena los números y se va
corriendo el iterador de dos en dos
*/

int main() {
    int n;
    set<int> num;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        num.insert(i);
    }
    auto it = next(num.begin());
    while (num.size() > 1) {
        printf("%d ",*it);
        auto aux = it;
        it = next(it);
        num.erase(aux);
        if (it == num.end()) {
            it = num.begin();
        }
        it = next(it);
        if (it == num.end()) {
            it = num.begin();
        }
    }
    printf("%d\n",*num.begin());
    return 0;
}
