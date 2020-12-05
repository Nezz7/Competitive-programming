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
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, k;
    cin >> n >> k;
    int g = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        g = __gcd(a[i],g);
    }
    int x = g % k;
    set<int> st;
    for(int i = 0; i < k; i++){
        st.insert(x);
        x = (x + g) % k;
    }
    cout << st.size() << endl;
    for(auto x : st) cout << x << " ";
   
}