#include <bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cin >> n;
    string s[n];
    int sz[n];
    for (int i = 0; i < n; i++){
        cin >> s[i];
        sz[i] = s[i].size();
    }
    for (int i = n - 1; i > 0;i--){
        bool cond = false;
        for (int j = 0; j <min(sz[i],sz[i-1]); j++){
            if (s[i][j] == s[i-1][j]) continue;
            if (s[i-1][j] < s[i][j]){
                cond =  true;
                break;
            }
            if (s[i-1][j] > s[i][j]){
                cond = true;
                sz[i-1] = j;
                break;
            }
        }
        if (!cond && sz[i-1] > sz[i]) sz[i-1] = sz[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < sz[i]; j++) cout << s[i][j];
    cout <<"\n";
    }
}
