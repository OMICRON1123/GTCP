#include <bits/stdc++.h>
using namespace std;

int factorial (int n) {
    if (n <= 1)
        return 1;
    else
        return n*factorial(n-1);
}

int main() {
    int res;
    string s;
    vector<int> let(26);
    vector<char> curr;
    set<vector<char> > done;
    vector<vector<char> > per;
    cin>>s;
    for (int i=0;i<s.size();i++) {
        let[s[i]-97]++;
        curr.push_back(s[i]);
    }
    res = factorial(s.size());
    for (int i=0;i<26;i++) {
        res /= factorial(let[i]);
    }
    printf("%d\n",res);
    sort(curr.begin(),curr.end());
    do {
        if (done.find(curr) == done.end()) {
            for (int i=0;i<curr.size();i++) {
                printf("%c",curr[i]);
            }
            printf("\n");
            done.insert(curr);
        }
    } while (next_permutation(curr.begin(),curr.end()));
    return 0;
}
