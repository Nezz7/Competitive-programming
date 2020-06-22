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
int a[MAXN], b[MAXN];
vector <int> r;
vector <int> l;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    LL k;
    cin >> n >> m >> k;
    vector<pair<LL,LL>> v;
    for (LL i = 1; i*i <= k ; i++){
        if (k  % i == 0){
                v.emplace_back(i,k/i);
            if (k/i != i){
                v.emplace_back(k/i,i);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cur = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == 0 && cur){
            l.pb(cur);
            cur = 0;
        }else cur++;
    }
    l.pb(cur);
    for (int i = 0; i < m ; i++)
        cin >> b[i];
    cur = 0;
    for (int i = 0; i < m; i++){
        if (b[i] == 0  && cur){
            r.pb(cur);
            cur = 0;
        }else cur++;
    }
    r.pb(cur);
    for (int i = 0)
}