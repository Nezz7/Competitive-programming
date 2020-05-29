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
int const MAXN = 2000 + 9;
int a[MAXN], c[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m, d;
    cin >> n >> m >> d;
    int sum = 0;
    for(int i = 0; i < m; i++){
        cin >> c[i];
        sum += c[i];
    }
    int idx = -1;
    for(int i = 0; i < m; i++){
        sum -= c[i];
        int cur = idx + d + c[i];
        if(sum > n - cur){
            idx += d + n - cur - sum;
        } else idx += d ;
        for(int j = 0; j < c[i]; j++){
            a[idx + j] = i + 1;
        }
        idx += c[i] - 1;
    }
    if(n - idx <= d){
        cout << "YES"<< endl;
        for(int i = 0; i < n; i++) cout << a[i] << ' ';
    }else cout << "NO" << endl;
}