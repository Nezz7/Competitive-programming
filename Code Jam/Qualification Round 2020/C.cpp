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
int const MAXN = 5000+ 9;
vector<int> inv[MAXN];
int l[MAXN],r[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int ca = 0;
    while (T--){
        int n;
        ca ++;
        cin >> n;
        for(int i = 0; i <= 25*60; i++) inv[i].clear();
        char ans [n + 1];
        for(int i = 1; i <= n; i++){
            cin >> l[i] >> r[i];
            inv[l[i]].pb(i);
            inv[r[i]].pb(-i);
        }
        for(int i = 0; i <= 25*60; i++) sort(all(inv[i]));
        bool cond = true;
        int c = -1, j = -1;
        for(int i = 0; i <= 25*60; i++){
           /* if (sz(inv[i])){
                cout << i << ' ' << c << " " << j << endl;
            }*/
            for (auto cur : inv[i]){
                if (cur < 0){
                    if (c == -cur) c = -1;
                    if (j == -cur) j = -1;
                }else {
                    if (c != -1 && j != -1) cond = false;
                    if (c == -1){
                        c = cur;
                        ans[cur] = 'C';
                    }else j = cur,ans[cur] = 'J';
                }
            }
        }
        if (!cond){
            cout << "Case #"<< ca << ": IMPOSSIBLE"  << endl;
        }else {
            cout << "Case #"<< ca << ": ";
            for (int i = 1; i <= n; i++) cout << ans[i];
            cout << endl;
        }
    }
}