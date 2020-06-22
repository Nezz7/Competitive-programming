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
        int n;
        cin >> n;
        set<LL> st;
        bool cond = true;
        for(int i = 0; i < n; i++){
            LL x;
            cin >> x;
            x %= n;
            x += n;
            x += i;
            x %= n;
            if(st.count(x)) cond = false;
            st.insert(x);
        }
        if(cond) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}