#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
LL a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i <n; i++)
        cin >> a[i];
    int start;
    LL mx  = *max_element(a,a+n);
    for (int i = 0; i < n; i++)
        if (mx == a[i]) start = i;
    int i = start;
        vector<int> cur;
        LL x = 0;
        LL s = 0;
        if (i) x = a[i - 1];
        for (int j = i - 1; j >= 0; j--){
            x = min (x,a[j]);
            cur.pb(x);
            s += x;
        }
        reverse(all(cur));
        cur.pb(a[i]);
        x = a[i];
        s+=x;
        for (int j= i + 1; j < n; j++){
            if (x > a[j]){
                x = a[j];
                s+= x;
                cur.pb(x);
            }else {
                s+= x;
                cur.pb(x);
            }
        }
    for (auto x : cur) cout << x << " ";

}