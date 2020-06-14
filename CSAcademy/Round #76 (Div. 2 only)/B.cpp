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
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> out;
    int nbr = 0;
    while(m--){
        int t;
        cin >> t;
        if(t == 1){
            int x;
            cin >> x;
            if(a[x]) a[x]--;
            else out.pb(x);
        }else nbr++;
    }
    while(sz(out) < nbr) out.pb(1);
    for(auto x : out) cout << x << endl;
}