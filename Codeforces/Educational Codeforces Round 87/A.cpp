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
        LL a,b,c,d;
        cin >> a >> b >> c >> d;
        if(b >= a){
            cout << b << endl;
            continue;
        }
        if(b < a && d >= c){
            cout << -1 << endl;
            continue;
        }
        a -= b;
        LL nbr = (a + c - d -1)/(c - d) * c + b;
        cout << nbr << endl;
    }
}