#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define LL long long int
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set  st;
map<int,set<int>> mp ;
LL get_num (LL len){
    return len * (len + 1) / 2;
}
int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        mp[-y].insert(x);
    }
    LL ans = 0;
    for (auto cur : mp){
        LL sz = cur.second.size();
        ans += get_num(sz);
        for (auto x : cur.second){
            st.erase(x);
        }
        set<int> vis;
        for (auto x : cur.second){
            int p = st.order_of_key(x);
            LL l = max(p,0);
            LL r = max ((int)st.size() - p, 0);
           if (vis.size()){
                    auto it =  vis.end();
                    it --;
                    int y = st.order_of_key(*it);
                    l-=y;
                    l = max(l,0LL);
           }
            ans += l*r;
            vis.insert(x);
        }
        LL s = st.size();

        ans += sz * s;
        for (auto x : cur.second){
                st.insert(x);
        }
    }
    cout << ans << "\n";
}
/*
6
1 1
3 1
5 1
6 1
2 0
4 0*/
