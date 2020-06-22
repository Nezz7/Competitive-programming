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
int const MAXN = 2e6 + 9;
int a[MAXN], pref[MAXN],suf[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        a[i] = ((s[i] == '(') ? 1 : -1);
    }
    int best = 0;
    int l = 1, r = 1;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            swap(a[i],a[j]);
            int cur = 0;
            int mn = 0;
            for (int k = 0; k < n; k++){
                if (k == 0)  pref[k] = a[k];
                else pref[k] = a[k] + pref[k - 1];
                mn = min(pref[k],mn);
            }
             for (int k = n-1; k >= 0; k--){
                if (k == n-1)  suf[k] = a[k];
                else suf[k] = a[k] + suf[k + 1]; 
                if (suf[k] > 0) suf[k] = -1e9;

            }
            for (int k = 0; k < n ; k++){
                if( pref[k] == mn && pref[n-1] == 0) cur++;
            }
    
            if (cur > best){
                l = i + 1;
                r = j + 1;
                best = cur;
            }
            swap(a[i],a[j]);
        }
    }

    cout << best << endl << l << " " << r << endl;
}