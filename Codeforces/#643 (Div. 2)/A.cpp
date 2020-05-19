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
LL get(LL x){
    vector<int> v;
    while(x > 0){
        v.pb(x % 10);
        x /= 10;
    }
    LL a = *min_element(all(v));
    LL b = *max_element(all(v));
    return a * b;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        LL x, k;
        cin >> x >> k;
        k--;
        for(int i = 0; i < k; i++){
            LL c = get(x);
            if(c == 0) break;
            x += c;
        }
        cout << x << endl;
    }
}