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
LD const pi = acos(-1);
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        n *= 2;
        LD area =  (LD) n/(4 * tan(pi/n));
        LD A = cos(pi/n)/sin(pi/n)* n/ 4.0;
        LD rr = 1.0/(2*sin(pi/n));
        LD ap = 1.0/(2* tan(pi/n));
        LD r = ap/cos(pi/n);
        LD d = cos(pi/n)/sin(pi/n);
        cout << d << " " << r << ' ' << ap << endl;
        cout << area << ' ' << A << endl; 
    }
}