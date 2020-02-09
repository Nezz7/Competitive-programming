#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 3e5+9;
int n;
int  a[MAXN][4];
bool vis[MAXN];
bool v[MAXN];

vector<int> num[MAXN];
vector<int> edges;
int start = 0;
bool inside (int x, int i){
    for (int j = 0; j <3;j++){
        if (a[i][j] == x) return true;
    }
    return false;
}
void DFS (int nbr, int node){
    vis[node] = true;
    edges.push_back(node);
    int x ,y;
    if (nbr == start){
        for (int  i = 0; i < 3; i++){
            if (a[node][i] == nbr){
                 x = a[node][(i + 1) % 3];
                 y = a[node][(i + 2) % 3];
            }
        }
    for (int i = 0; i < num[x].size() ;i++){
        for (int j = 0; j < num[y].size() ;j++){
            if (num[x][i] == num[y][j] && num[x][i]!=node){
                DFS(x,num[x][i]);
            }
        }
    }
    }else {
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3 ;j++){
                if (i == j ) continue;
                for (int u = 0; u < num[a[node][i]].size();u++){
                    for (int v = 0; v< num[a[node][j]].size();v++){
                        if (num[a[node][i]][u] == num[a[node][j]][v] && !vis[num[a[node][j]][v]])
                            DFS(i,num[a[node][j]][v]);
                }
            }
        }

    }
    }

}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n ;
    for (int i = 0; i < n - 2;i++){
        for (int j = 0; j <3; j++){
            cin >> a[i][j];
            num[a[i][j]].push_back(i);
        }
    }
    for (int i = 1; i<= n ;i++){
        if (num[i].size() == 1) start = i;
    }
    DFS(start,num[start][0]);
    for (int k = 0 ; k < edges.size(); k++){
        int node = edges[k];
        if (k == (int) edges.size() - 1 or k == (int) edges.size() - 2){
             for (int j = 0; j < 3; j++)
                  if (!v[a[node][j]]){
                        cout << a[node][j]<<" ";
                        v[a[node][j]] = true;
                  }
        }else{
        vector<pair<int,int>> b;
        for (int j = 0; j < 3; j++){
            int s= 0;
             for (int x = 1; x <3;x++)
             s+=inside(a[node][j],edges[k+x]);
             b.emplace_back(s,a[node][j]);
        }
        sort(b.begin(),b.end());
        for (auto cur : b){
             //cout << cur.first <<" " << cur.second << endl;
            if (!v[cur.second]){
            v[cur.second] = true;
            cout<< cur.second<<" ";
            }
        }
    }
    }
}
