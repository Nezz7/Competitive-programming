#include <bits/stdc++.h>
using namespace std;
set<pair<int,int>>adj[4];
int n;
vector<int> out;
bool ok (int i,int cur){
    if (i == n){
        cout << "Possible\n";
        for (auto cur  : out ) cout << cur << " ";
        return true;
    }
    auto it = adj[cur%3].upper_bound ({cur,1e9});
    if (it == adj[cur%3].begin()) return false;
    it--;
    int x = it->second;
    cur = it->first;
    adj[cur%3].erase({cur,x});
    out.push_back(x);
    return ok(i+1,cur+1);
}
int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        adj[(x%3)].insert({x,i+1});
    }
    int cur = 0;
    if (ok(0,0)){
    }else cout << "Impossible";
}
