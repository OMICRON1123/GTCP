#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a;
    scanf("%d",&n);
    vector<bool> arr(n);
    while (--n) {
        scanf("%d",&a);
        arr[a-1] = 1;
    }
    for (int i=0;i<arr.size();i++) {
        if (!arr[i]) {
            printf("%d",i+1);
            break;
        }
    }
    return 0;
}
