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
map<vector<int>,LD> dp;
map<vector<int>,LD> dp2;
LL p[MAXN];
int n;
LD  solve (vector <int> a){
    if (is_sorted(all(a))){
       return 0;
    }
    if (dp.count(a)) return dp[a];
    vector<int> v;
    long double x = 0;
    int nb = 0;
    for (int  i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[min(i,j)] > a[max(i,j)]){
                nb++;
            }
    for (int  i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[min(i,j)] > a[max(i,j)]){
                v = a;
                swap(v[i],v[j]);
                x += (1/(LD)(n*n)) * solve(v);
            }
        }
    }

    return dp[a] = ((LD)(n*n) / (LD) (nb) ) * (1 + x);
}
LD  solve2 (vector <int> a){
    if (is_sorted(all(a))){
        return 0;
    }
    if (dp2.count(a)) return dp2[a];
    vector<int> v;
    long double x = 0;
    int nb = 0;
     for (int  i = 0; i < n-1; i++){
        int j = i + 1;
        if (a[i] > a[j]){
            nb++;
        }
    }

    for (int  i = 0; i < n-1; i++){
        int j = i + 1;
        if (a[i] > a[j]){
            v = a;
            swap(v[i],v[j]);
            x += (1/(LD)(n-1)) * solve2(v);
        }
    }
    return dp2[a] = ((LD)(n-1) / (LD) (nb) ) * (1 + x);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        dp.clear();
        dp2.clear();
        cin >> n;
        vector<int> a (n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long double ans = solve(a);
        long double ans2 = solve2(a);
        cout <<fixed << setprecision(6) << "Monty "<<  ans << " Carlos ";
        cout << ans2 << endl;
     }
}