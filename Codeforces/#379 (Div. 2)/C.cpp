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
map<int,int> id;
set<int> st;
int a[MAXN],c[MAXN],b[MAXN],d[MAXN];
int A[MAXN], B[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n,m,k;
    cin >> n >> m >> k;
    LL x, s;
    cin >> x >> s;
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    for(int j = 0; j < m; j++){
        cin >> b[j];
        st.insert(b[j]);
    }
    for(int i = 0; i < k; i++){
        cin >> c[i];
    }
    for(int j = 0; j < k; j++){
        cin >> d[j];
        st.insert(d[j]);
    }
    int cur = 0;
    st.insert(0);
    vector<LL> cost;
    for(auto x : st){
        id[x] = cur;
        cost.pb(x);
        cur++;
    }
    for(int i = 0; i <= sz(st); i++) A[i] = x;
    for(int i = 0; i < m; i++){
        int x = b[i];
        int have = a[i];
        A[id[x]] = min(have,A[id[x]]);
    }
    for(int i = 1; i < sz(st); i++){
        A[i] = min(A[i - 1],A[i]);
    }
    for(int i = 0; i < k; i++){
        int x = d[i];
        int have = c[i];
        B[id[x]] = max(have,B[id[x]]);
    }
    for(int i = 1; i < sz(st); i++){
        B[i] = max(B[i],B[i - 1]);
    }
    LL ans = x * n;
    for(int i = 0; i < m; i++){
        LL spend = b[i];
        LL t = A[id[spend]];
        LL have = s - spend;
        if(have >= 0){
            auto it = upper_bound(all(cost),have);
            it--;
            LL to = B[id[*it]];
            LL cur = (n - to) * t;
            ans = min(ans,cur);
        }
    }
    for(int i = 0; i < k; i++){
        LL spend = d[i];
        LL to = B[id[spend]];
        LL have = s - spend;
        if(have >= 0){
            auto it = upper_bound(all(cost),have);
            it--;
            LL t = A[id[*it]];
            LL cur = (n - to) * t;
            ans = min(ans,cur);
        }
    }
    cout << ans << endl;
}