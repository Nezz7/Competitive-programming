#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    char a[n][m];
    vector<pair<int,char>> v [m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j];
        }
    }
    for(int j = 0; j < m; j++){
        char c = a[0][j];
        int cur = 1;
        for(int i = 0; i < n; i++){
            if(c == a[i][j]) cur++;
            else {
                v[j].pb({cur,c});
                cur = 1;
                c = a[i][j]
            }
        }
        v[j].pb({cur,c});
    }
    int last[m];
    for(int j = 0; j < m; j++){
        LL cur = 0;
        for(int i = 1; i < sz(v[j]) - 1; i++){
            int x =
            if( v[i].first <= v[i+1].first && v[i],first <= v[i-1].first){
                cur++;
            }
        }
    }
}