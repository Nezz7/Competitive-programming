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
    int n;
    string s;
    cin >> s;
    n = s.size();
    int ans = 4;
    int open = 0, l = -1;
    for(int i = 0; i < n; i++){
       if(s[i] == '[') open = 1;
       if(s[i] == ':' && open){
        l = i;
        break;
       }
    }
    int close = 0, r = -1;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == ']') close = 1;
        if(s[i] == ':' && close){
            r = i;
            break;
       }
    }
    if(l == -1 or r == -1 or l >= r) return cout << -1, 0;
    for(int i = l; i < r; i++) ans += (s[i] == '|');
    cout << ans << endl;
}