#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e5+9;
set<int>adj[MAXN];
int p [MAXN];
int vis[MAXN];
vector<int> get_fact (int x){
    vector<int> ret;
    while (x > 1) {
        int d = p[x];
        //cout << d << x << endl;
        ret . push_back(d);
        while (x % d ==0)
            x/=d;
    }
    return ret;
}
void add (int x){
    if (vis[x]){
        cout << "Already on \n";
        return;
    }
    vector<int> pr = get_fact(x);
    bool cond = true;
    int y;
    for (auto cur : pr){
        if (adj[cur].size()){
            cond = false;
            y = *(adj[cur].begin());
            break;
        }
    }
    if (cond){
        cout << "Success \n";
        vis[x] = 1;
        for (auto cur : pr)
            adj[cur].insert(x);
        return ;
    }
    cout << "Conflict with " << y << "\n";
}
void del (int x){
    if (vis[x] == 0){
        cout << "Already off \n";
        return;
    }
    vis[x] = 0;
    vector<int> pr = get_fact(x);
    int y;
    for (auto cur : pr){
       adj[cur].erase(x);
    }
    cout << "Success \n";
}
int main (){
   ios_base::sync_with_stdio(0);
   cin.tie(0),cout.tie(0);
   p[1] = 1;
   for (int i = 2; i < MAXN; i++){
        if (!p[i])
        for (int j = i; j <MAXN; j+=i){
                p[j] = i;
        }
   }
   int n, m;
   cin >> n >> m;
   while (m--){
        int x;
        string s;
        cin >> s >> x;
        if (s == "+"){
            add(x);
        }else del(x);
   }
}
