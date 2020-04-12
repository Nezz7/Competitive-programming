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
int const MAXN = 100 + 9;
string s [MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int cc = 0;
    while (T--){
        cc++;
        int n;
        cin >> n;
        int mx = 0;
        for (int i = 0; i < n; i++){
            cin >> s[i];
            mx = max(sz(s[i]),mx);
        }
        bool cond  = true;
        string ans = "";
        int idx[n];
        for(int i = 0; i < n; i++) idx[i] = 0;
        while (true){
            int c = -1;
            for (int i = 0; i < n; i++){
                if (idx[i] >= sz(s[i]) or s[i][idx[i]] == '*') continue;
                if (c == -1) c = s[i][idx[i]],ans += (char) c;
                else if (c != s[i][idx[i]]) cond = false;
                idx[i]++;
            }
            if(c == -1) {
                for (int i = 0; i < n; i++){
                    idx[i]++;
                }
            }
            bool terminal = true;
            for(int i = 0; i < n; i++){
                if(idx[i] < sz(s[i])) terminal = false;
            }
            if (terminal or !cond) break;
        }
       
        cout << "Case #"  << cc << ": ";
        if (cond) cout << ans << endl;
        else cout << '*' << endl; 
    }
}