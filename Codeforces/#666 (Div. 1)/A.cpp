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
LL a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << "1 1" << endl;
        cout << -a[0] << endl;
        cout << "1 1\n0\n";
        cout << "1 1\n0\n";
        return 0;
    }
    cout << n << " " << n << endl;
    cout << -a[n - 1] << endl;
    a[n - 1] = 0;
    cout << 1 << " " << n - 1 << endl;
    for(int i = 0; i < n - 1; i++){
        cout << a[i] * (n - 1) << " ";
        a[i] = a[i] + a[i] * n - a[i];
    }
    cout << endl;
    cout << 1 << " " << n << endl;
    for(int i = 0; i < n ; i++){
        cout << - a[i]  << " ";
    }
}