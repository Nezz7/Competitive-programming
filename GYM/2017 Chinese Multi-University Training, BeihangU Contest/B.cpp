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
LL mod = 1e9+ 7;
LL p[MAXN],id[26];
string s[MAXN];
vector<pair<vector<int>,int>>g;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    p[0] = 1; 
    for (int i  = 1; i < MAXN; i++){
        p[ i ] =  (26 * p[i-1])% mod ;
    }
    int n;
    int c = 0;
    while( cin >> n ){
        c++;
        g.clear();
        g.resize(26);
        int m = 0;
        set < int > st;
        for(int i = 0 ; i < 26 ; ++i) st.insert(i);
        for( int i = 0; i < n; i++){
            cin >> s[i];
            if(sz(s[i]) > 1) st.erase((int)(s[i][0] - 'a'));
            reverse(all(s[i]));
            m = max(sz(s[i]),m);
        }
        for (int c = 0; c < 26; c++){
                vector<int> v (2 * m,0);
                for(int i  = 0; i < n; i++){
                    for (int j = 0; j < sz(s[i]); j ++){
                        v[j] += (s[i][j] == (c + 'a'));
                    }
                }
                for(int i = 0 ; i < 2 * m - 1; ++i){
                    int dv = v[i] / 26;
                    v[i] %= 26;
                    v[i + 1] += dv;
                }
                reverse(all(v));
                g[c].first = v;
                g[c].second = c;
        }
        
        sort(rall(g));
        int i = 25;
        int idx = -1;
        for(int i = 25 ; i >= 0 ; --i)
            if(st.find(g[i].second) != st.end()){
                idx = g[i].second;
                id[idx] = 0;
                break;
            }
        for(auto cur : g)
            if(cur.second != idx) 
                id[cur.second] = i --;
        
        LL ans = 0;
        for(int i = 0; i < n; i++){
            for (int j = 0; j < sz(s[i]); j++){
                char c = s[i][j] - 'a';
                ans += (p[ j] * id[c]) % mod;
                ans %= mod;
            }
        }
        cout <<"Case #"<< c <<": " << ans << endl;
    }
}
