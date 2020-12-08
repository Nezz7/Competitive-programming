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
int const MAXN = 109;
int a[MAXN][MAXN];
int n, m;
vector<vector<pair<int,int>>> out;
void flip(pair<int,int> xx){
    int x = xx.first;
    int y = xx.second;
    a[x][y] ^= 1;

}
void add(pair<int,int> a){
    out.back().push_back(a);
    flip(a); 
}

void go (int x, int y){

    if(x + 1 > n) x--;
    if(y + 1 > m) y--; 
    int cnt = 0;
    vector<pair<int,int>> p[2];
    for(int i = x; i <= x + 1; i++){
        for(int j= y; j <= y + 1; j++){
                cnt += a[i][j];
                p[a[i][j]].emplace_back(i, j);
        }
    }
    if(cnt == 0) return;
     if(cnt == 3){
        out.emplace_back();
        add(p[1][0]);
        add(p[1][1]);
        add(p[1][2]);
    }
    if(cnt == 1 or cnt == 2){
        out.emplace_back();
        add(p[1][0]);
        add(p[0][0]);
        add(p[0][1]);
        go(x,y);
    }
    if(cnt == 4){
        out.emplace_back();
        add(p[1][0]);
        add(p[1][1]);
        add(p[1][2]);
        go(x,y);
    }
   

}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        out.clear();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                char x;
                cin >> x;
                a[i][j] = x - '0';
            }
        }
        if(m & 1)
        for(int i = 1; i <= n; i++){
            if(a[i][m]) {
                if(i + 1 <= n && a[i+1][m]){
                    out.emplace_back();
                    add({i,m});
                    add({i + 1,m});
                    add({i, m - 1});
                    i++;
                }else {
                    out.emplace_back();
                    add({i,m});
                    if(i - 1 >= 1)
                    add({i - 1, m - 1});
                    else add({i + 1, m - 1});
                    add({i, m - 1}) ;              
                }
            }
        }
        if(n& 1)
        for(int j = 1; j <= m; j++){
             if(a[n][j]) if(j + 1 <= m && a[n][j+1]){
                    out.emplace_back();
                    add({n,j});
                    add({n,j + 1});
                    add({n - 1, j});
                    j++;
                }else {
                    out.emplace_back();
                    add({n,j});
                    if(j - 1 >= 1)
                    add({n -1, j - 1});
                    else add({n -1, j + 1});
                    add({n -1, j}) ;              
                }
            
        }

          for(int i = 1; i <= n; i+= 2){
            for(int j = 1; j <= m; j+= 2){
                go(i, j);
            }
        }
        cout << sz(out) << endl;
        for(auto cur : out){
            for(auto x : cur){
                cout << x.first << ' ' << x.second << " ";
            }
            cout << endl;
        }
        for(int i = 1; i<= n; i++){
            for(int j= 1; j <= m; j++){
               assert(a[i][j] == 0);
            }
        }
    }
}