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
int const MAXN = 200 + 9;
int b[MAXN],a[MAXN];
set<int> st;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        st.clear();
        for(int i = 1; i <= 2 * n; i++)
            st.insert(i);
        for(int i = 0; i < n; i++){
            cin >> b[i];
            st.erase(b[i]);
        }
        bool cond = true;
        for(int i = 0; i < n; i++){
            int idx  = 2*i;
            a[idx] = b[i];
            auto it = st.upper_bound(b[i]);
            if(it == st.end()){
                cond = false;
                break;
            }else {
                a[idx + 1] = *it;
                st.erase(*it);
                st.erase(b[i]);
            }
        }
        if(cond == false) cout << -1 << endl;
        else{
            for(int i = 0; i < 2 * n; i++)
                cout << a[i] << ' ';
            cout << endl;
        }
    }
}