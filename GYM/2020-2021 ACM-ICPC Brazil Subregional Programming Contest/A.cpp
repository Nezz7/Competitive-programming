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
int a[20][20];
bool valid (int x, int  y){
    return x >= 1 && x <= 10 && y >= 1 && y <= 10 && a[x][y] <= 1;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    bool cond = true;
    while(n--){
        int d, r, c, l;
        cin >> d >> l >> r >> c;
        for(int i = 0; i < l; i++){
            if(d == 0){
                a[r][c + i]++;
                cond &= valid(r, c + i);
            }else {
                a[r + i][c]++;
                cond &= valid(r + i, c);
            }
        }
        
    }
    
    cout << (cond? 'Y':'N') << endl;
}