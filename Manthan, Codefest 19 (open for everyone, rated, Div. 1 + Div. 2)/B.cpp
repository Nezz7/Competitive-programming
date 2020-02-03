#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
set<int> st;
int const MAXN = 3000;
int a[MAXN];
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i],mp[a[i]]++;
    for (auto cur : mp){
        if (cur.second > 1) st.insert(cur.first);
    }
    if (st.size() == 0 ){
        cout << 0;
        return 0;
    }
    int ans = n;
    for (int i = 0; i < n; i++){
        map<int,int> o = mp ;
        set<int> s = st;
        for (int j = i; j < n; j++){
            o[a[j]]--;
            if (o[a[j]] <= 1) s.erase(a[j]);
            if (s.size() == 0) {
                 ans = min (ans,j-i + 1);
                 break;
            }
        }
    }
    cout << ans << "\n";

}
