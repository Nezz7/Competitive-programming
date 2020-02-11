#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e5+9;
vector<vector<string>>adj;
int idx[11];
string out[MAXN][3];
int main (){
    int n;
    cin >> n;
    adj.resize(11);
    int mx = 0,mn = 100;
    for (int i = 0; i < n;i++){
        string s;
        cin >> s;
        adj[(int)s.size()].push_back(s);
        mx = max((int)s.size(),mx);
        mn = min((int)s.size(),mn);
    }
    string c;
    cin >> c;
    for (int i=0; i <= 10;i++){
        sort(adj[i].begin(),adj[i].end());
    }

    int id = 0;
    for (int i = 0; i <= 10 ;i++){
        while  (idx[i] < adj[i].size()){
            out[id][0] = adj[i][idx[i]++];
            out[id][1] = adj[mn+mx-i][idx[mn+mx-i]++];
            out[id][2] = c;
            id++;

        }
        if (id == n/2) break;
    }
    string go[id];
    for(int i = 0; i <id;i++){
        string   a = out[i][0] + c;
        string   b = out[i][1] + c;
        if (a < b){
            go[i] = a + out[i][1];
        }else go[i] = b + out[i][0];
    }
    sort(go,go+id);
    for (auto cur : go)
        cout << cur << "\n";
}
