#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e6 + 9;
int p[MAXN];
vector<int> v;
void get_div (LL x){
    v.clear();
    for (LL i = 2; i*i <= x ; i++){
        if (x % i == 0){
            v.push_back(i);
            if (x/i != i){
                v.push_back(x/i);
            }
        }
    }
    sort (v.begin(),v.end());
}
int main(){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    for (int i = 2; i < MAXN ; i++)
        if (!p[i])
            for (int j = i; j < MAXN; j+=i)
                p[j] = i;
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        LL a[n];
        map<LL,LL>mp;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a,a+n);
        LL ans = a[0] * a[n-1];
        get_div(ans);
        if (v.size() != n) {
            cout << -1 <<"\n";
            continue;
        }
        bool cond = true;
        for (int i = 0 ; i < n; i++){
            if (a[i] != v[i]) cond = false;
        }
        if (cond ) {
            cout << ans << "\n";
        }else cout << -1 << "\n";

    }

}
