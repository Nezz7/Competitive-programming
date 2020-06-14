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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> out;
        out.pb(a[0]);
        int last = a[1];
        for(int i = 1; i < n - 1; i++){
            if(a[i] < a[i + 1] && out[sz(out) - 1] < last){
                last = a[i + 1];
                continue;
            }
            if(a[i] > a[i + 1] && out[sz(out) - 1] > last){
                last = a[i + 1];
                continue;
            }
            out.pb(a[i]);
            last = a[i + 1];
        }
        out.pb(last);
        cout << sz(out) << endl;
        for(auto x : out) cout << x << ' ';
        cout << endl;
    }
}