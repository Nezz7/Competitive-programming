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
    LL x;
    cin >> x;
    if(x == 1){
        cout << "no" << endl;
        return 0;
    }
    set<int> st;
    for(LL i = 2; i * i <= x; i++){
        if(x % i == 0) st.insert(i);
        while(x % i == 0){
            x/= i;
        }
    }
    if( x > 1) st.insert(x);
    if(sz(st) == 1) cout << "yes" << endl;
    else cout << "no" << endl;
}