#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 300 + 9;
vector<vector<int>> a;
int n,m;
int getr(vector<int> v){
    int ret = 0;
    int n = v.size();
    for(int i = 0; i < n; i++){
        int mn = 1e9;
        int idx = -1;
        for(int j = i; j < n; j++){
            if(v[j] < mn){
                mn = v[j];
                idx = j;
            }
        }
        if(idx != i){
            swap(v[i],v[idx]);
            swap(a[i],a[idx]);
            ret++;
        }
    }
    return ret;
}
int getc(vector<int> v){
    int ret = 0;
    int nn = v.size();
    for(int i = 0; i < nn; i++){
        int mn = 1e9;
        int idx = -1;
        for(int j = i; j < nn; j++){
            if(v[j] < mn){
                mn = v[j];
                idx = j;
            }
        }
        if(idx != i){
            swap(v[i],v[idx]);
            for(int k = 0; k < n; k++){
                swap(a[k][i],a[k][idx]);
            }
            ret++;
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    a.assign(n,vector<int> (m));
     for (int i = 0; i < n; i++){
        for (int j = 0; j <m; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    vector<int> r;
    vector<int> sr;
    for(int i = 0; i < n; i++){
        r.pb(1e9);
        for(int j = 0; j < m;j++){
            r[i] = min(a[i][j],r[i]);
        }
    }
    int cnt = 0;
    sr = r;
    sort(all(sr));
    ans+= getr(r);
    vector<int> c;
    vector<int> sc;
    for(int j = 0; j < m;j++){
        c.pb(1e9);
        for(int i = 0; i < n; i++){
            c[j] = min(a[i][j],c[j]);
        }
    }
    sc = c;
    sort(all(sc));
    ans+= getc(c);
    bool cond = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != (i * m + j + 1)) cond = false;
        }
    }
    if (cond)
    cout << ans;
    else cout << "*";
}