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
int const MAXN = 1e5 + 9;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int cc = 0;
    while (T--){
        cc++;
        int u;
        cin >> u;
        LL last = 1;
        for(int i = 0; i < u - 1; i++) last *= 10;
        vector<pair<LL,string>> v;
        set<char> all;
        set<char> nonzero;
        map<char,int> mp;
        vector<pair<int,char>> v2;
        for (int i = 0; i < 1e4; i++){
            LL q;
            string s;
            cin >> q >> s;
            v.emplace_back(q,s);
            mp[s[0]]++;
            for(auto c : s)
            all.insert(c);
            nonzero.insert(s[0]);
        }
        for(auto cur : mp){
            v2.emplace_back(cur.second,cur.first);
        }
        sort(all(v));
        string ans = "";
        for(auto x : all){
            if(!nonzero.count(x)) ans+= x;
        }
        for(int i = 0; i < sz(v); i++){
            LL q = v[i].first;
            string s = v[i].second;
            if(q < 10){
                if(sz(ans) == q && ans.find(s[0]) == std::string::npos){
                    ans += s[0];
                }
            }else {
                int n = log10(q);
                int x = q;
                while(q > 10){
                    q /= 10;
                }
                 if(sz(ans) == q && n + 1== sz(s) && ans.find(s[0]) == std::string::npos){
                    ans += s[0];
                }
            }
        }
        sort(all(v2));
        reverse(all(v2));
        for(auto cur : v2){
             if(ans.find(cur.second) == std::string::npos){
                    ans +=  cur.second;
                }
        }
        cout << "Case #"  << cc << ": " << ans << endl;
    }
}