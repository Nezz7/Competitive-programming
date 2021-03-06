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
int const MAXN = 2e6 + 9;
int a[100][100];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        set<int> row, col;
        for(int i = 0; i < n; i++) row.insert(i);
        for(int i = 0; i < m; i++) col.insert(i);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                if(a[i][j]) row.erase(i), col.erase(j);
            }
        int cnt = 0;
        for(int k = 0; k < 2*max(n,m); k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(!col.count(j) or !row.count(i)) continue;
                    a[i][j] = 1;
                    cnt++;
                    col.erase(j);
                    row.erase(i);
                }
            }
        }
        if(cnt & 1) cout << "Ashish" << endl;
        else cout << "Vivek" << endl;
    }
}