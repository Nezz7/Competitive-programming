#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e3+9;
char d [] = {'N','S','E','W'};
int dy[] = {0,0,1,-1};
int dx[] = {-1,1,0,0};
int D[MAXN][MAXN];
int R[MAXN][MAXN];
int n, m;
vector < pair < char ,int > > dir ;
vector< pair <pair <int,int>, char> > start;
string ans = "";
bool valid (int ii, int jj, int i, int j , int x){
    if (ii < 1 or ii > n or jj < 1 or jj > m) return false;
    if (i == ii){
        int mx = max (jj, j);
        int mn = min (jj, j);
        if ( (R[i][mx] - R[i][mn-1]) != x+1) return false;
    }
    if (j == jj){
        int mx = max (ii, i);
        int mn = min (ii, i);
        if ( ( D[mx][j] - D [mn-1][j]) != x+1) return false;
    }
    return true;
}
bool go (int i, int j){
    for (auto cur : dir ){
        char c = cur .first;
        int x = cur.second;
        int ii,jj;
        for (int  k = 0 ; k < 4 ; k++){
            if ( d[k] == c ){
                ii = i + x*dx[k];
                jj = j + x*dy[k];
            }
        }

        if (!valid (ii,jj,i,j,x)) return false;
        i = ii;
        j = jj;
    }
    return true;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= m ; j++){
            char c;
            cin >> c;
            if (c == '#'){
                    D [i][j] = -1 + D [i-1][j];
                    R [i][j] = -1 + R [i][j-1];
            }else{
                    D [i][j] = 1 + D [i-1][j];
                    R [i][j] = 1 + R [i][j-1];
            }
            if (c != '#' && c != '.'){
                start.emplace_back(make_pair(i,j),c);
            }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k ; i++){
        char c;
        int x;
        cin >> c >> x;
        dir.emplace_back (c,x);
    }
    for (auto cur : start ){
        if (go(cur.first.first,cur.first.second)) ans+=cur.second;
    }
    sort (ans.begin(),ans.end());
    if (ans.size() == 0) cout << "no solution \n";
    else cout << ans << "\n";
}
