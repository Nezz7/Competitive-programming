#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less_equal<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set  st;
int main (){
    ios_base::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
        cin >> a[i],v.emplace_back(a[i],-i);
    int q;
    cin >> q;
    sort(v.rbegin(),v.rend());
    vector<pair<pair<int,int>,int>> query;
    int i =0;
    while (q--){
        int k,p;
        cin >> k >> p;
        p--;
        query.push_back({{k,p},i});
        i++;
    }
    sort(query.begin(),query.end());
    int ans[query.size()];
    for (int i =0; i <query.size();i++){
        int sz =st.size();
        for (int k = sz; k < query[i].first.first;k++){
            st.insert({abs(v[k].second),v[k].first});
        }
        int p = query[i].first.second;
        auto it = (st.find_by_order(p));
        ans[query[i].second] = it->second;
    }
    for (auto cur : ans) cout << cur << "\n";
}
