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
int const MAXN = 2000+ 9;
int row[MAXN][MAXN],a[MAXN][MAXN],col[MAXN][MAXN];
int cntC[MAXN][MAXN],cntR[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char c ;
            cin >> c;
            a[i][j] = (c == 'B');
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if ( j == 0) row[i][j] = a[i][j];
            else row[i][j] = row[i][j-1] + a[i][j];
        }
    }
    for (int j = 0; j < n; j++){
        for (int i = 0; i < n; i++){
            if ( i == 0) col[j][i] = a[i][j];
            else col[j][i] = col[j][i-1] + a[i][j];
        }
    }
    int ans  = 0;
    for (int i = 0; i < n; i++){
        ans += (row[i][n-1] == 0);
        ans += (col[i][n-1] == 0);
    }
    for(int j = 0; j < n - k + 1; j++){
        int cur = 0;
        for (int i = 0; i < k; i++){
            int r = row[i][j + k - 1];
            int l = 0;
            if(j > 0) l = row[i][j -1];
            cur += ((r - l) == row[i][n-1]);
        }
        cntR[0][j] = cur; 
        for (int i = k; i < n; i++){
            //add
            int r = row[i][j + k - 1];
            int l = 0;
            if(j > 0) l = row[i][j -1];
            cur += ((r - l) == row[i][n-1] && (r - l));
            //del
            r = row[i - k][j + k - 1];
            l = 0;
            if(j > 0) l = row[i - k][j -1];
            cur -= ((r - l) == row[i - k][n-1] && (r - l));
            cntR[i - k + 1][j] = cur;
        }
    }
    for (int i = 0; i < n - k + 1; i++){
        int cur = 0;
        for (int j = 0; j < k; j++){
            int r = col[j][i + k - 1];
            int l = 0;
            if (i > 0) l = col[j][i- 1];
            cur += ((r - l) == col[j][n-1] && (r - l));
        }
        cntC[i][0] = cur;
        for(int j = k; j < n; j++){
            //add
            int r = col[j][i + k - 1];
            int l = 0;
            if (i > 0) l = col[j][i- 1];
            cur += ((r - l) == col[j][n-1] && (r - l));
            //del
            r = col[j - k][i + k - 1];
            l = 0;
            if (i > 0) l = col[j - k][i-1];
            cur -= ((r - l) == col[j - k][n - 1] && (r - l));
            cntC[i][j - k + 1] = cur;
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mx = max(mx,cntR[i][j] + cntC[i][j]);
        }
    }
    cout << ans + mx << endl;
    
}