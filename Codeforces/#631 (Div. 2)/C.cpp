#include <bits/stdc++.h>
#define f first
#define s second
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
int pref[MAXN],suf[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n + 9; i++) pref[i] = suf[i] = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        set<int> st;
        int mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(a[i],mx);
            st.insert(a[i]);
            if (mx == sz(st) && mx == i + 1) pref[i] = 1;     
        }
        st.clear();
        mx = 0;
        for(int i = n -1 ; i>= 0; i--){
            mx = max(a[i],mx);
            st.insert(a[i]);
            if (mx == sz(st) && mx == n - i) suf[i] = 1;  
        }
       /*for(int i = 0; i < n; i++){
            cout << pref[i] << ' ';
        }
        cout << endl;
        for(int i = 0; i < n; i++){
            cout << suf[i] << ' ';
        }
        cout << endl;*/
        vector<pair<int,int>> out;
        for (int i = 0; i < n -1; i++){
            if (pref[i] == suf[i+1] && pref[i]) out.pb({i+1,n - i - 1});
        }
        cout << sz(out) << endl;
        for(auto cur : out) {
            cout << cur.first << " " << cur.second << endl; 
        }
    }
}