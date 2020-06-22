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
    multiset<int> st;
    multiset<int> old;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    old = st;
    int ans = -1e9;
    for(int i = 0; i < n; i++){
        multiset<int> in;
        st = old;
        int sum = 0;
        for(int j = i; j < n; j++){
            in.insert(a[j]);
            auto it = st.find(a[j]);
            st.erase(it);
            sum += a[j];
            vector<int> mn;
            vector<int> mx;
            for(int p = 0; p < min(j - i + 1, min(k,n - (j - i + 1))); p ++){
                if( !sz(st) or *in.begin() >= *st.rbegin() ) break;
                mn.pb(*in.begin());
                mx.pb(*st.rbegin());
                sum -= *in.begin();
                sum += *st.rbegin();
                in.erase(in.begin());
                auto it = st.find(*st.rbegin());
                st.erase(it);
            }
            ans = max(ans,sum);
            for(auto x : mn){
                sum += x;
                in.insert(x);
            }
            for(auto x : mx){
                sum -= x;
                st.insert(x);
            }
        }
    }
    cout << ans << endl;
    
}