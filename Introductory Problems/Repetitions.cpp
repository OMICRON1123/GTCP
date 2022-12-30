#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    char ch = s[0];
    int cont = 1,curr = 1;
    for (int i=1;i<s.size();i++) {
        if (s[i] == ch) {
            cont++;
            if (i == s.size()-1 && cont > curr)
                curr = cont;
        }
        else {
            curr = cont > curr ? cont : curr;
            cont = 1;
            ch = s[i];
        }
    }
    printf("%d\n",curr);
    return 0;
}
