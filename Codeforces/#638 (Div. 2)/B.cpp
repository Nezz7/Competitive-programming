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
int const MAXN = 1000 + 9;
int a[MAXN],pref[MAXN];
int main(){
    //ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        set <int> st;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            st.insert(a[i]);
        }
        pref[0] = 0;
        for(int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + a[i];
        bool cond = true;
        LL cur = pref[k];
        for(int i = k - 1; i < n; i++){
            if(pref[i+1] - pref[i - k + 1] != cur) cond = false;
        }
        if(cond){
            cout << n << endl;
            for(int i = 0; i < n; i++){
                cout << a[i] << ' ';
            }
            cout << endl;
            continue;
        }
        if(sz(st) > k){
            cout << -1;
            cout << endl;
            continue;
        }
        cout << n * k << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < k - sz(st); j++) cout << 1 << ' ';
            for(auto cur : st) cout << cur << ' ';
        }
        cout << endl;
    }
}