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
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for(int i = n - 2; i >= 0 && k; i--,k--){
            a[n - 1] += a[i];
        }
        cout << a[n - 1] << endl;

    }
}