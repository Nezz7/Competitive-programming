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
int pmin[MAXN], pmax[MAXN];
int smin[MAXN], smax[MAXN];
int val[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        for(int i = 0; i <= n + 9; i++){
            pmin[i] = 0;
            smin[i] = 0;
            pmax[i] = 0;
            smax[i] = 0;
            val[i] = 0;
        }
        int cur = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '-') cur--;
            else cur ++;
            val[i + 1] = cur;
            pmax[i + 1] = max(pmax[i],cur);
            pmin[i + 1] = min(pmin[i],cur);
        }
        cur = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '-') cur++;
            else cur --;
            smax[i + 1] = max(smax[i + 2],cur);
            smin[i + 1] = min(smin[i + 2],cur);
        }
        while(q--){
            int l, r;
            cin >> l >> r;
            int v = val[l - 1];
            int l1 = pmin[l - 1];
            int r1 = pmax[l - 1];
            cout << l1 << " " << r1 << endl;
            int l2 = v + smin[r + 2];
            int r2 = v + smax[r + 2];
            cout << l2  - v << " " << r2 - v << endl;
            cout << l2 << " " << r2 << endl;
            cout << v << endl;
            l = min(l1,l2);
            r = max(r1,r2);
            cout << l << " " << r << endl;
            cout << r - l + 1 << endl;
        }

    }
}