#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

void combinations(vector<int> aux,int idx) {
    if (idx == vec.size()) {
        for (int i=0;i<aux.size();i++) {
            printf("%d ",aux[i]);
        }
        printf("\n");
        return;
    }
    aux.push_back(vec[idx]);
    combinations(aux, idx+1);
    aux.pop_back();
    combinations(aux,idx+1);
}

int main() {
    vec = {1,2,3,4,5};
    vector<int> aux;
    combinations(aux,0);
    return 0;
}
