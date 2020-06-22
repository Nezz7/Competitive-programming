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
    while (t--){
        int x,a,b;
        cin >> x >> a >> b;
        while(x > 20 && a){
            a--;
            x = x/2 + 10;
        }
        while(x > 0 && b){
            b--;
            x-=10;
        }
        if ( x > 0){
            cout << "NO" << endl;
        }else cout << "YES" << endl;
    }
}