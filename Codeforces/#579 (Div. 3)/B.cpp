#include <bits/stdc++.h>
using namespace std;
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        n = 4* n;
        map<int,int> mp;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            mp [x]++;
        }
        vector<int> v;
        bool cond = true;
        for (auto cur : mp){
            if (cur.second%2) cond = false;
            v.push_back(cur.first);
        }
        int L = 0, R = v.size() - 1;
        int ans = v[L]*v[R];
        while (L <= R){
            if (mp[v[L]] != mp[v[R]] or v[L] * v[R] != ans) cond = false;
            L++;
            R--;
        }
        if (cond) cout << "YES\n";
        else cout << "NO\n";
    }
}
