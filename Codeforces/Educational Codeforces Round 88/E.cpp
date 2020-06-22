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
LL h, c, t;
LL f(LL x){
    return abs(x * h + x * c - 2 *x * t) ;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> h >> c >> t;
        LL l = 0, r = 100;
        LD ans = abs(h - t);
        int out = 1;
       for(int i = 1; i <= 20; i+=2){
           int x = (i + 1) / 2;
           int y = (i) / 2;
           LD cur = abs((x * h + y *c) /(LD) i - t);
           cout << cur << endl;
           if(cur < ans){
               ans = cur;
               out = i;
           }
       }
        cout << out << endl;
    }
}