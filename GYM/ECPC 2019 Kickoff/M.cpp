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
    freopen("lis.in","r",stdin);
    ios_base::sync_with_stdio (0),cin.tie(0);
    string s;
    cin >> s;
    if(s.size() == 1){
        cout << s << endl;
        return 0;
    }
    bool cond = true;
    for(int i = 1; i < s.size(); i++){
        if(s[i] != '9') cond = false;
    }
    LL ans = 0;
    LL n = s.size();
    if(cond == true){
        for(auto c : s){
             ans += c - '0';
        }
    }else {
        ans = s[0] - 1 - '0';
        ans += 9 * (n - 1);
    }
    cout << ans << endl;
}