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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<int> cnts(26,0), cntt(26,0);
        for(int i = 0; i < n; i++){
            ++cnts[s[i] - 'a'];
            ++cntt[t[i] - 'a'];
        }
        bool cond = true;
        bool good = false;
        for(int i = 0; i < 26; i++){
            if(cnts[i] != cntt[i]) cond = false;
            good |= cnts[i] > 1;
        }
        if(!cond){
            cout << "NO" << endl;
            continue;
        }
        if(good){
            cout << "YES" << endl;
            continue;
        }
        int invs = 0, invt = 0;
        for(int l = 0; l < n; ++l){
            for(int r = 0; r < l; ++r){
                invs += s[l] > s[r];
                invt += t[l] > t[r];
            }
        }
        cond &= (invs & 1) == (invt & 1);
        if(cond) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}