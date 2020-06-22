#include <bits/stdc++.h>
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 100 + 9;
int b[MAXN][MAXN];
int a[MAXN][MAXN];
int dx[]={0,0,1,1};
int dy[]={0,1,0,1};
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<pair<int,int>> out;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            bool cur = true;
            for (int k  = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if (!a[x][y]) cur = false;
            }
            if (cur){
                out.emplace_back(i,j);
                for (int k  = 0; k < 4; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    b[x][y] = 1;

                }
            }
        }   
    }             
    bool cond = true;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != b[i][j]) cond = false;
        }
    }
    if (cond){
        cout << sz(out) << endl;
        for (auto cur : out){
            cout << cur.first + 1 << ' ' << cur.second  + 1<< endl;
        }
    }else cout << -1;
}