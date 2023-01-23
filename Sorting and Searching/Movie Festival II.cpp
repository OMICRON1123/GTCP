#include <bits/stdc++.h>
using namespace std;

/*
Para este caso lo mejor es q cada persona vea la pel�cula que est� m�s pronta a terminar.
No obstante hay que tener en cuenta que si una persona que ya ha visto otras pel�culas
puede verse la siguiente esto es mejor a que una persona nueva entre a esta ya que la persona
nueva se podr�a usar a futuro con otra pel�cula que comience antes.
*/

int main() {
    int n,k,cont=1;
    scanf("%d%d",&n,&k);
    vector<pair<int,int> > movie(n);
    multiset<int> member;
    for (int i=0;i<n;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        movie[i] = make_pair(b,a);
    }
    sort(movie.begin(),movie.end());
    member.insert(movie[0].first);
    for (int i=1;i<n;i++) {
        auto it = member.upper_bound(movie[i].second);
        if (it != member.begin()) {
            member.erase(prev(it));
            member.insert(movie[i].first);
            cont++;
        }
        else if (member.size() < k) {
            member.insert(movie[i].first);
            cont++;
        }
    }
    printf("%d\n",cont);
    return 0;
}
