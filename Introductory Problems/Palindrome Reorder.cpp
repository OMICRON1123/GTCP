#include <bits/stdc++.h>
using namespace std;

int main() {
    int odd = 0,idx;
    string s;
    vector<int> let(26);
    cin>>s;
    for (int i=0;i<s.size();i++) {
        let[s[i]-65]++;
    }
    for (int i=0;i<26;i++) {
        if ((let[i]&1) == 1) {
            odd++;
            idx = i;
        }
    }
    if (odd > 1) {
        printf("NO SOLUTION\n");
    }
    else {
        string res = "";
        for (int i=0;i<26;i++) {
            if (i == idx)
                continue;
            for (int j=0;j<(let[i]>>1);j++) {
                res += (char) (i+65);
            }
        }
        if (odd == 1) {
            for (int i=0;i<let[idx];i++) {
                res += (char) (idx+65);
            }
        }
        for (int i=25;i>=0;i--){
            if (i == idx)
                continue;
            for (int j=0;j<(let[i]>>1);j++) {
                res += (char) (i+65);
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}
