#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN  = 5000;
multiset<int> d [MAXN];
set<int> t [MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int n, m;
    cin >> n >> m;
    int a[n];
    int c = 0;
    for (int  i = 0; i < n; i++)
        cin >> a[i], c += (a[i] != 0);
    while (m --){
        int u , v;
        cin >> u >> v;
        v--;
        d[u] . insert(v);
        t[v] . insert(u);
    }
    int ans = 0;
    int day = 0;
    while (c){
    cout << " day = " << day << endl;
        ans ++;
        day++;
        vector<pair<int,int>>v;
        for (auto cur : d[day]){
            if (a[cur]){
                v.emplace_back(-*(t[cur].upper_bound(day)),cur);
            }
        }
        sort(v.begin(),v.end());
        for (auto cur : v ){
            cout << cur .first << " " << cur.second << endl;
        }
        cout << endl << endl;
        for (int i = 0; i < min(ans,(int)v.size()); i++){
            int cur = v[i].second;
            a[cur]--;
            if (a[cur] == 0) c--;
        }
        ans -= v.size();
        ans = max(ans,0);
        v.clear();
        if (c && ans >=2){
            for (int i = 0 ; i < n;i++){
                if (a[i])
                    for (int j = 0; j < a[i]; j ++){
                        auto it =(t[i].upper_bound(day));
                        if (it == t[i].end())
                        v.emplace_back(0,i);
                        else
                        v.emplace_back(-(*it),i);
                    }
            }

            sort(v.begin(),v.end());
             for (auto cur : v ){
            cout << cur .first << " " << cur.second << endl;
        }
            int id = 0;
            while (ans>=2 && c && id < v.size()){
                int cur = v[id].second;
                a[cur]--;
                if (a[cur] == 0) c--;
                ans-=2;
            }
        }

    }
    cout << day;

}
