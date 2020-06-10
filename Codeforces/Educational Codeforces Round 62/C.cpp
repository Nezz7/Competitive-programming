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
pair<LL,LL> a[MAXN];
LL need[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i].second >> a[i].first;
    sort(a, a + n);
    multiset<LL> st;
    LL cur = 0;
    for(int i = n - 1; i >= 0; i--){
        if(sz(st) < k - 1){
            st.insert(a[i].second);
            cur += a[i].second;
        }else {
            LL mn = *st.begin();
            if(a[i].second > mn){
                st.erase(st.begin());
                cur -= mn;
                st.insert(a[i].second);
                cur += a[i].second;
            }
        }
        need[i] = cur;
    }
    LL ans = 0;
    for(int i = 0; i < n; i++){
        LL cur = a[i].first *(a[i].second + need[i + 1]);
        ans = max(cur,ans);
    }
    cout << ans << endl;

}