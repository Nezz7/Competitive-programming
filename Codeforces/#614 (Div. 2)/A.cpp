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
        int n,s,k;
        cin >> n >> s >> k;
        set<int> st;
        for(int i = 0; i < k; i++){
            int x;
            cin >> x;
            st.insert(x);
        }
        int ans = 1e9;
        for(int i = -1002; i <= 1002;i++){
            if(i + s <= n && i + s >= 1 && !st.count(i+s)){
                ans = min(abs(i),ans);
            }
        }
        cout << ans << endl;
    }
}