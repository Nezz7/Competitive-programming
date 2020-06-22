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
int const MAXN = 7000 + 9;
LL b[MAXN];
int a[MAXN],better[MAXN][MAXN];
int removed[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int cur = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            LL no = ~b[j];
            LL cur = no & b[i];
            better[i][j] = (__builtin_popcountll(cur) > 0);
        }
    }
    vector<int> sum(n);
    for(int i = 0; i < n; i++){
        int cur = 0;
        for(int j = 0; j < n; j++){
            cur += better[i][j];
        }
        sum[i] = cur;
    }
    int tot = n - 1;
    for(int it = 0; it < n; it++){
        int id = max_element(all(sum)) - sum.begin();
        if(sum[id] == tot){
            tot --;
            for(int i = 0; i < n; i ++){
                sum[i] -= better[i][id];
            }
            removed[id] = 1;
            sum[id] = 0;
        }
    }
    LL ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
            if(!removed[i]) ans+= a[i],cnt++;
    }
    if(cnt < 2) ans = 0;
    cout << ans << endl;
}