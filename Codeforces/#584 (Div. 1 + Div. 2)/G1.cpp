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
int frq[MAXN],r[MAXN];
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        frq[a[i]]++;
        r[a[i]] = i;
    }
    int cur = -1;
    int mx = 0;
    int sum = 0;
    int ans = 0;
    set<int> st;
    for(int i = 0; i < n; i++){
        cur = max(r[a[i]],cur);
        if(cur == i){
            st.clear();
            ans += sum - mx;
            mx = 0;
            sum = 0;
            cur = -1;
            continue;
        }
        if(!st.count(a[i])){
            st.insert(a[i]);
            sum += frq[a[i]];
            mx = max(mx,frq[a[i]]);
        }
    }
    cout << ans << endl;
}