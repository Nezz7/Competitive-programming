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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int a,b;
        cin >> a >> b;
        if (a == b) cout << 0 << endl;
        else 
        if (a > b ) {
            int x = a - b;
            if (x & 1) cout << 2 << endl;
            else cout << 1 << endl;
        }else {
            int x = b - a;
            if (x & 1) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }
}