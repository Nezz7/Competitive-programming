#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 3e6+9;
int occ[MAXN];
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie(0);
    int n;
    cin >> n;
    int a [n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool is_valid = true;
    vector<int> ans;
    int start = 0;
    int cur = 0;
    set<int> st;
    for (int i = 0 ; i < n ;i++){
        if (a[i]  > 0 ){
            occ[a[i]] ++;
            cur++;
            if (occ[a[i]] > 1 or st.count(a[i])) is_valid = false;
            st.insert(a[i]);
        }else {
            if (occ[-a[i]] == 0) is_valid = false;
            occ[-a[i]] --;
            cur --;
        }
        if (cur == 0){
            ans.push_back(i+1- start);
            st.clear();
            start = i+1;
        }
    }
    if (cur) is_valid = false;
    if (is_valid){
        cout << ans.size() << "\n";
        for (auto cur : ans ) cout << cur << " ";
    }else cout << -1;
}
