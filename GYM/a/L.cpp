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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    sort(a, a + n);
    bool cond = false;
    for(int i = 2; i < n; i++){
        if(a[i] < a[i - 1] + a[i - 2]) cond = true;
    }
    if(cond) cout << "possible" << endl;
    else cout << "impossible" << endl;
}