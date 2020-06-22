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
bool is_pal (string s){
    int n = s.size();
    for (int i = 0; i < s.size()/ 2 ; i++){
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}
map<string,int> mp;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    string p ="";
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        if (is_pal(s)) p = s; 
        else
        mp[s]++;
    }
    string ans ="";
    for (auto& cur : mp){
        string x = cur.first;
        string rx = cur.first;
        reverse(all(rx));
        if(mp[x] && mp[rx]){
            ans+=x;
            cur.second = 0;
        }

    }
    int x = sz(p) + 2*sz(ans);
    cout << x << endl;
    cout << ans << p ;
    reverse(all(ans));
    cout << ans <<endl;
}