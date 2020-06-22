#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
int pref[MAXN][2];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        string s;
        cin >> n >> s;
        pref[0][1] = 0;
        pref[0][0] = 0;
        for (int i = 0; i  < n; i++){
            if (s[i] == 'L'){
                pref[i + 1][0] = pref[i][0]  - 1;
                pref[i + 1][1] = pref[i][1]; 
            }
            if (s[i] == 'R'){
                pref[i + 1][0] = pref[i][0]  + 1;
                pref[i + 1][1] = pref[i][1]; 

            }
            if (s[i] == 'U'){
                pref[i + 1][1] = pref[i][1]  + 1;
                pref[i + 1][0] = pref[i][0];
            }
            if (s[i] == 'D'){
                pref[i + 1][1] = pref[i][1]  - 1;
                pref[i + 1][0] = pref[i][0];
            }
        }
        int len = 1e9;
        map<pair<int,int>,int> mp;
        int L = 0, R = 0;
        mp[{0,0}] = 0;
        for (int i = 1; i <= n; i++){
            //cout << pref[i][0] << " " << pref[i][1] << " " << endl;
            if (mp.count({pref[i][0],pref[i][1]})){
                int l = mp[{pref[i][0],pref[i][1]}];
                if (len > i - l + 1){
                    len = i - l + 1;
                    L = l + 1;
                    R = i;
                }
            }
            mp[{pref[i][0],pref[i][1]}] = i;
        }
        if (len == 1e9){
            cout << -1 << endl;
        }else cout << L << " " << R << endl;
    }
}