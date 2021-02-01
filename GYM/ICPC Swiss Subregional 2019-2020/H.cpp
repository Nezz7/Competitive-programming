#include <bits/stdc++.h>
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
map<vector<int>,string> mp;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        vector<int> occ(26,0);
        for(auto c : s){
            occ[c - 'a']++;
        }
        if(mp.count(occ)){
            mp[occ] = min(s, mp[occ]);
        }else mp[occ] = s;
    }
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        string ans ="";
        for(int i = 1; i < (1<<9); i++){
            vector<int> occ(26,0);
            for(int j = 0; j < 9; j++){
                int b = !!(i & (1 << j));
                if(b) occ[s[j] - 'a']++;
            }
            if(mp.count(occ)){
                string a = mp[occ];
                if(sz(a) > sz(ans)) ans = a;
                if(sz(a) == sz(ans)) ans = min(a,ans);
            }
        }
        if(sz(ans)) cout << ans << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
}