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
    int x = 0,y = 0;
    while(t--){
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(a > b) swap(a,b);
        if(c == '?'){
            if(a >= x  && b >= y) cout << "YES" << endl;
            else cout << "NO" << endl;
        }else {
            x = max(x,a);
            y = max(y,b);
        }
    }
}