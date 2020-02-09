#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        int n = s.size();
        vector<int> ans;
        for (int i = 0; i <  n - 4 ; i++){
            if (s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && s[i+3] == 'n' && s[i+4] == 'e'){
                ans.push_back(i+3);
                s[i+2] = '1';
            }
        }
        for (int i = 0; i <  n - 2 ; i++){
            if (s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e'){
                ans.push_back(i+2);
            }
            if (s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o'){
                ans.push_back(i+2);
            }
        }
        cout << ans.size() << "\n";
        for (auto x : ans) cout << x << " ";
        cout <<"\n";
    }
}
