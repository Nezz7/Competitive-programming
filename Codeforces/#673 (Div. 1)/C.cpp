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
int n;
LL cnt[32][2];
void solve(int idx, vector<int>& a){
    if(idx < 0 or sz(a) <= 1) return;
    int one = 0, zero = 0;
    vector<int> o, z;
    for(int i = 0; i < sz(a); i++){
        int b = !!(a[i] & (1LL << idx));
        if(b){
            cnt[idx][1] += zero;
            o.push_back(a[i]);
            one++;
        }else {
            cnt[idx][0] += one;
            z.push_back(a[i]);
            zero++;
        }
    }
    solve(idx - 1, z);
    solve(idx - 1, o);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    solve(31, a);
    LL ret = 0, inv = 0;
    for(int i = 31; i >= 0; i--){
        if(cnt[i][1] < cnt[i][0]){
            ret |= (1LL << i);
            inv += cnt[i][1];
        }else inv += cnt[i][0];

    }
    cout << inv << " " << ret;
}