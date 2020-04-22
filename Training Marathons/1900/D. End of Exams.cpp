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
LD const eps = 1e-9;
vector<vector<pair<int,LD>>> out;
bool eq(LD a, LD b){
    return abs(a-b) <= eps;
}
bool ls(LD a, LD b){
    LD d = a - b;
    if ( d <= eps) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, w, m;
    cin >> n >> w >> m;
    cout << fixed << setprecision(6);
    out.resize(m);
    bool cond = true;
    LD sum = n * w / (LD) m;
    LD cur = 0;
    int idx = 0;
    for(int i = 1; i <= n; i++){
        if(idx == m){
            cond = false;
            break;
        }
        if(ls(cur + w, sum) or eq(cur + w, sum)){
            cur += w;
            out[idx].pb({i,w});
            if(eq(cur,sum)) idx++,cur = 0;
            continue;
        }else {
            LD d = sum - cur;
            out[idx].pb({i,d});
            idx++;
            cur = w - d;
            out[idx].pb({i,cur});
            if(eq(cur,sum)) idx++,cur = 0;
            if(ls(sum,cur)){
                cond = false;
                break;
            }
        }
    }
    if (cond){
        cout << "YES" << endl;
        for (int i = 0; i < m; i++){
            for(auto cur : out[i]){
                cout << cur.first << ' ' << cur.second  << ' ';
            }
            cout << endl;
        }
    }else cout << "NO" << endl;

}
