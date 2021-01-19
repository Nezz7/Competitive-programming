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
LL occ[MAXN];
LL cnt[50][50];
int const mod = 1e9 + 7;
vector<int> get(LL x){
    vector<int> occ(32,0);
    if(x < 0) return occ;
    int on = 0;
    for(int i = 30; i >= 0; i--){
        int b = !!(x & (1LL << i));
        if(b){
            for(int j = 0; j <= i; j++){
                occ[j + on] = (cnt[i][j] + occ[j + on]) % mod;
            }
            on++;
        }
    }
    occ[on] ++;
    return occ;
}

vector<int> get(int l, int r){
    vector<int> a = get(l - 1);
    vector<int> b = get(r);
    for(int i = 0; i < sz(a); i++){
        b[i] = (b[i] + mod - a[i]) % mod;
    }
    return b;
}
LL ans[100];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for(int i = 0; i < 32; i++){
        cnt[i][0] = cnt[i][i] = 1;
        for(int j = 1; j < i; j++){
            cnt[i][j] = (cnt[i - 1][j - 1] + cnt[i - 1][j]) % mod;
        }
    }
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 0){
            int l, r, x;
            cin >> l >> r >> x;
            r--;
            x %= mod;
            vector<int> a = get(l, r);
            for(int i = 0; i <= 30; i++){
                ans[i] = (ans[i] + ((LL)a[i] * 1LL * x) % mod) % mod;
            }
        }else {
            int l, r;
            cin >> l >> r;
            r--;
            LL sum = 0;
            for(int i = l; i <= r; i++){
                sum = (sum + ans[30 - i]) % mod;
            }
            cout << sum << endl;
        }
    }
}