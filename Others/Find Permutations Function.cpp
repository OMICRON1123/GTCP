#include <bits/stdc++.h>
using namespace std;

vector<bool> chosen;
vector<int> vec;

void permutations(vector<int> aux) {
    if (aux.size() == vec.size()) {
        for (int i=0;i<aux.size();i++)
            printf("%d ",aux[i]);
        printf("\n");
    }
    else {
        for (int i=0;i<vec.size();i++) {
            if (!chosen[i]) {
                aux.push_back(vec[i]);
                chosen[i] = true;
                permutations(aux);
                aux.pop_back();
                chosen[i] = false;
            }
        }
    }
}

int main() {
    vec = {1,2,3,4};
    for (int i=0;i<vec.size();i++)
        chosen.push_back(0);
    vector<int> aux;
    permutations(aux);
}
