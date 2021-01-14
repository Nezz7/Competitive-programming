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
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        LL sum = 0;
        LL mx = 0;
        for(int i = 0; i < n; i++){
            LL cur;
            cin >> cur;
            sum += cur;
            mx += (cur + x - 1) / x;
        }
        cout << (sum + x - 1) / x << ' ' << mx << endl;
    }
}