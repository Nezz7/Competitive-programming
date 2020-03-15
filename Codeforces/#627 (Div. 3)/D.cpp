#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
using namespace __gnu_pbds;
int const MAXN = 2e6 + 9;


typedef tree<pair<int,int>, null_type, less <pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set  st;
    int n, k, a , m;
int get_next(int x){
    int i = st.order_of_key(x);
    auto it = st.find_by_order(i);>
    if (it == st.end()) return n+1;
    return *it;
}
int  get_prev (int x){
    int i = st.order_of_key(x);
    auto it = st.find_by_order(i-1);
    if (i - 1 < 0) return 0;
    return *it;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int a[n],b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < n; j++)
        cin >> b[j];
    int ans = 0;
    for (int i = n-1; i >= 0; i--){
        ans += st.order_of_key({a[i] - b[i],-1});
        st.insert({b[i] - a[i],i})
    }
    cout << ans << endl;
    
}