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
    freopen("abc.in", "r", stdin);
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char,int> st;
    for(auto c : s) st[c]++;
    if(st.size() == 1){
        cout << 0 << endl;
        return 0;
    }
    if(st.size() == 2){
        if(st.count('b')) cout << 0 << endl;
        else cout << -1 << endl;
        return 0;
    }
    string g ="";
    for(auto cur : st){
        while(cur.second --){
            g.push_back(cur.first);
        }
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i++){
        ans1 += s[i] != g[i];
    }
    reverse(all(g));
    for(int i = 0; i < n; i++){
        ans2 += s[i] != g[i];
    }
    cout << (min(ans1, ans2) + 1) / 2;

}