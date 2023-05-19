#include <bits/stdc++.h>
using namespace std;

/*
Crear una matriz que cuente todos los árboles que hay en todos los
posible rectángulos q se pueden formar desde la esquina superior de la
matriz.
*/

int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    vector<vector<int>> grid(n+1,vector<int>(n+1));
    for (int i=0;i<n;i++) {
        string s;
        cin>>s;
        for (int j=0;j<n;j++) {
            if (s[j] == '.') {
                grid[i+1][j+1] = grid[i+1][j]+grid[i][j+1]-grid[i][j];
            }
            else {
                grid[i+1][j+1] = 1+grid[i+1][j]+grid[i][j+1]-grid[i][j];
            }
        }
    }
    while(q--) {
        int y1,y2,x1,x2;
        scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
        printf("%d\n",grid[y2][x2]-grid[y2][x1-1]-grid[y1-1][x2]+grid[y1-1][x1-1]);
    }
    return 0;
}
