#include <bits/stdc++.h>
using namespace std;

int main() {
    //n es la cantidad de palos
    int n;

    //best es el mejor costo hasta el momento
    //cost es el costo de convertir todos los palos a cierta longitud
    //small es la cantidad de palos que son más pequeños o iguales a cierta longitud
    //great es la cantidad de palos que son más grandes a cierta longitud
    long long best,cost = 0,small = 0,great;

    //se lee el valor de n
    scanf("%d",&n);

    //en el vector p se van a guardar las longitudes de los palos
    vector<long long> p(n);

    //en el vector dis se van a guardar pares en los que el primer valor es cierta
    //longitud y el segundo valor es la cantidad de veces que esta se repite
    vector<pair<long long,long long> > dis;

    //se leen las longitudes de los palos
    for (int i=0;i<n;i++) {
        scanf("%lld",&p[i]);
    }

    //se ordena el vector de longitudes
    sort(p.begin(),p.end());

    //se inserta el primer elemento al vector dis que corresponde a la primera
    //longitud y el valor 1 ya que solo se ha contado un palo con esta longitud
    dis.push_back(make_pair(p[0],1));

    //este for termina de llenar el vector dis
    for (int i=1;i<n;i++) {
        //si el valor de la longitud actual es igual al del anterior se aumenta en 1
        //el segundo valor del último par agregado
        if (p[i] == dis[dis.size()-1].first) {
            dis[dis.size()-1].second++;
        }
        //si no es igual se crea un nuevo par y se indica que solo se ha contado 1
        //palo con esta longitud
        else {
            dis.push_back(make_pair(p[i],1));
        }
        //el primer costo que calculamos es convertir todos los palos al palo de
        //menor longitud, por eso se le suma la distancia p[i] a p[0]
        cost += p[i]-p[0];
    }
    //por el momento el mejor costo que hemos hallado es el de convertir todos
    //a la longitud del palo más pequeño
    best = cost;

    //la cantidad de palos que son iguales al primero es dis[0].second
    small = dis[0].second;

    //la cantidad de palos mayores al primero es la cantidad total menos dis[0].second
    great = n - dis[0].second;

    /*
    Ahora hay que tener en cuenta que la longitud óptima a la que se deben convertir
    siempre será un valor de las longitudes ya dadas debido a que si consideramos
    una función F(x) que arroja el costo total para cierta longitud x que cumple que
    p[i] <= x < p[i+1] es decir que x está entre dos valores de longitudes, en este
    intervalo simpre habrá un número constante de valores p[i] menores o iguales a x,
    asumamos que el número de valores menores o iguales es m entonces
    F(x)=(x-p[1])+...+(x-p[m])+(p[m+1]-x)+...+(p[n]-x)
    Reagrupando los términos tenemos
    F(x) = (p[m+1]+...p[n])-(p[1]+...+p[m])+m*x-(n-m)*x
    Como p[i] <= x < p[i+1] entonces (p[m+1]+...+p[n])-(p[1]+...+p[m]) es una
    constante C y F(x) se puede escribir como
    F(x) = C+(2*m-n)*x
    Y debido a que esta es una función lineal en x su valor máximo siempre estará en
    alguno de los dos extremos, es decir, en x=p[i] o en x=p[i+1]
    */

    //Por lo tanto de la explicación anterior deducimos que solo debemos evaluar el
    //en las longitudes ya dadas, y eso lo hacemos en este for
    for (int i=1;i<dis.size();i++) {
        //curr es la distancia entre la nueva longitud y la longitud anterior
        long long curr = dis[i].first-dis[i-1].first;
        //el nuevo costo será el costo anterior más la cantidad de palos con
        //longitud menor a la anterior multiplicada por la distancia menos la
        //cantidad de palos con longitud mayor multiplicada por la distancia
        cost = cost + small*curr-great*curr;
        //ahora a la cantidad de palos con longitud menor o igual se debe aumentar en
        //la cantidad de palos con longitud actual y la cantidad de palos con longitud
        //mayor se debe disminuir en la cantidad de palos con longitud actual
        small += dis[i].second;
        great -= dis[i].second;
        //se hace la comparación de qué costo es menor
        best = cost < best ? cost : best;
    }
    //se imprime el menor costo
    printf("%lld\n",best);
    return 0;
}
