#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e5 + 9;
int n, k;
int d[MAXN],in[MAXN];
vector < vector <int> > lvl;
int main (){
    cin >> n >> k ;
    lvl = vector < vector <int> > (n+2);
    for (int i = 0; i < n ; i++){
        cin >> d[i];
        lvl[d[i]].push_back(i+1);
    }
    if (lvl[0].size()!=1){
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 1; i < n ; i++){
        if (lvl[i-1].size()==0 && lvl[i].size()){
            cout << -1 << "\n";
            return 0;
        }
    }
    vector < pair <int,int> > edges;
    for (int i = 1; i < n ; i++){
        int start = 0;
        for (auto cur : lvl[i]){
            if (start == lvl[i-1].size()){
                  cout << -1 << "\n";
                  return 0;
            }
            if (start < lvl[i-1].size() && in[ lvl[i-1][start] ]< k){
                edges.emplace_back (cur,lvl[i-1][start]);
                in [ cur ] ++;
                in[ lvl[i-1][start] ]++;
            }else {
                    start ++;
                    if (start < lvl[i-1].size() && in[ lvl[i-1][start] ]< k){
                        edges.emplace_back (cur,lvl[i-1][start]);
                        in[ lvl[i-1][start] ]++;
                        in [ cur ] ++;
                    }else {
                         cout << -1 << "\n";
                         return 0;
                    }
            }
        }
    }
    cout << edges.size() << "\n";
    for (auto cur : edges){
        cout << cur.first << " " << cur.second << "\n";
    }

}
