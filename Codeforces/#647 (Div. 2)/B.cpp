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
        set<int> st;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            st.insert(x);
        }
        int ans = -1;
        for(int i = 1; i <= 2*1024; i++){
            set<int> cur;
            for(auto x : st){
                cur.insert(x^i);
            }
            bool cond = true;
            for(auto x : st){
                if(!cur.count(x)){
                    cond = false;
                    break;
                }
            }
            if(cond){
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
}