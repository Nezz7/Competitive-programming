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
        LL n, m;
        cin >> n >> m;
        if(m == 0){
            cout << 0 << endl;
            continue;
        }
        LL tot = n * (n + 1) / 2;
        LL one = m;
        LL zero = n - m;
        if(zero < one ){
            cout << tot - zero << endl;
            continue;
        }
        LL a = zero / (one + 1);
        LL md = zero % (one + 1);
        LL other = one + 1 - md;
        LL b = (a + 1);
        tot -= other * (a * (a + 1) / 2 )+ md *(b * (b + 1) / 2);
        cout << tot << endl;
    }
}
