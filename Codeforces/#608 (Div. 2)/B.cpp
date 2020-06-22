#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN  = 2e6 + 9;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ans;
    for (int i = 0; i < n -1;i++){
        if (s[i] == 'B') continue;
        ans.push_back(i+1);
        if (s[i+1] == 'W') s[i+1] = 'B';
        else s[i+1] = 'W';
    }
    if (s[n-1] == 'B'){
        cout << ans.size() << "\n";
        for (auto cur : ans) cout << cur << " ";
    }else {
        if ((n - 1)% 2 ) cout << "-1";
        else {
            for (int i = 0; i < n-1;i+=2){
                 ans.push_back(i+1);
            }
             cout << ans.size() << "\n";
        for (auto cur : ans) cout << cur << " ";
        }
    }

}
