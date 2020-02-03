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
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        string s,t;
        vector<int> a[26];
        cin >> s >> t;
        for (int i  = 0; i < s.size(); i++){
            a[s[i] - 'a'].push_back(i);
        }
        int ans = 1;
        bool cond = true;
        int cur = -1;
        for (int i = 0; i < t.size(); i++){
            if (a[t[i]-'a'].size() == 0){
                    cond = false;
                     break;
            }
            int  c = t[i] - 'a';
            auto it = upper_bound(all(a[c]),cur);
            if (it == a[c].end()){
                ans ++;
                cur = -1;
                i--;
                continue;
            }
            cur = *it;
        }
        if (cond){
            cout << ans << endl;
        }else cout << -1 << endl;
    }
 }
