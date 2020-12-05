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
int arr[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        LL n;
        cin >> n;
        LL sum = 0;
        for(LL i = 1; i <= n; i++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum % n){
            cout << -1 << endl;
            continue;
        }
        vector<pair<pair<LL,LL>,LL>> out;
        for(LL i = 2; i <= n; i++){
            LL x = a[i]/i;
            LL m  = a[i] % i;
            m = (i - m) % i;
            a[1] -= m;
            a[i] += m;
            out.push_back({{1,  i}, m});
            out.push_back({{i,  1}, a[i]/i});
            a[1] += a[i];
            a[i] = 0;
        }
        bool cond = true;
        LL d = sum / n;
        for(LL i = 2; i <= n; i++){
            LL need = d - a[i];
            a[1] -= need;
            a[i] += need;
            out.push_back({{1, i}, need});
        }
     
        cout << sz(out) << endl;
        assert(sz(out) <= 3 * n);
        for(auto cur : out){
            LL i = cur.first.first;
            LL j = cur.first.second;
            LL x = cur.second;
            assert(x >= 0 && x <= 1e9);
            assert(i >= 1 && i <= n);
            assert(j >= 1 && j <= n);
            cout << i << " " << j << " " << x << endl;
        }

    }
}