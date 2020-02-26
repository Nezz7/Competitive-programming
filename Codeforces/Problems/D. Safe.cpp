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
int const MAXN = 40;
int n,m;
string  s[MAXN];
vector<int> c;
LL solve (int pos, vector<int> v){
    if (pos == n) {
        for (int i = 0; i < m; i++)
            if (v[i]) return 0;
        return 1;
    }
    LL ret = 0;
    vector<int> cur = v;
    bool cond = true;
    for (int i = 0; i < m; i++){
        if (s[i][pos] == '0')
            cur[i]--;
        if (cur[i] < 0) cond = false;
    } 
    if (cond) ret += solve(pos+1,cur);
    cur = v;
    cond = true;
    for (int i = 0; i < m; i++){
        if (s[i][pos] == '1')
            cur[i]--;
        if (cur[i] < 0) cond = false;
    } 
    if (cond) ret += solve(pos+1,cur);
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    c.resize(m);
    for (int i = 0; i < m; i ++){
        cin >> s[i] >> c[i] ;
    }
    cout << solve (0,c);

}