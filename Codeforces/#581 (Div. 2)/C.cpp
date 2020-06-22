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
int a[MAXN];
char c[104][104];
int d[104][104];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> c[i][j];
            c[i][j] -= '0';
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            d[i][j] = c[i][j];
            if(!d[i][j]) d[i][j] = 1e6;
        }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a[i];
        a[i]--;
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                d[i][j] = min((int) d[i][j],(int)d[i][k] + (int) d[k][j]);
            }
        }
    }
    int to = a[m - 1];
    vector<int> out;
    int i;
    out.pb(to + 1);
    int cur = 0;
    for(i = m - 2; i >= 0; i--){
        int from = a[i];
        cur++;
        if(d[from][to] == cur && to != from) continue;
        cur = 1;
        to = a[i + 1];
        out.pb(to + 1);
    }
    out.pb(a[0] + 1);
    reverse(all(out));
    cout << sz(out) << endl;
    for(auto x : out) cout << x << ' ';
}