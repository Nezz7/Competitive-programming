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
vector<LL> a, p;
int x;

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n >> x;
        a.clear();
        p.clear();
        LL ans = 0;
        bool cond = true;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            a.push_back(x);
            p.push_back(1);
        }
        
        for(int i = 0; i < a.size(); i++){
            if(cond && a[i] % x == 0){
                a.push_back(a[i]/x);
                p.push_back(p[i] * x);
            }else {
                cond = false;
            }
        }
        for(int i = 0; i < a.size(); i++){
            ans += p[i] * a[i];
        }
        cout << ans << endl;
    }
}