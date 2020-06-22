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
int const MAXN = 2e5 + 9;
int const K = log2(MAXN) + 1;
int a[MAXN],st[MAXN][K];
map<int,LL> result;
int gcd(int a, int b){
    if(a > b)return gcd(b, a);
    if(a == 0)return b;
    return gcd(b % a, a);
}
int lg[MAXN];
int get (int L, int R){
    int j = lg[R - L + 1];
    return gcd(st[L][j], st[R - (1 << j) + 1][j]);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    lg[1] = 0;
    for (int i = 2; i < MAXN; i++)
        lg[i] = lg[i/2] + 1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        st[i][0] = a[i];
    for (int j = 1; j < K; j++){
        for (int i = 0; i + (1 << j) <= n; i++){
            st[i][j] = gcd(st[i][j - 1],st[i + (1 << (j - 1)) ][j - 1]);
        }
    }
    for (int i = 0; i < n; i++){
        int to = i;
        while(to < n){
            int l = to, r = n - 1;
            int ans = to;
            while (l <= r){
                int mid = (l + r + 1) / 2;
                if (get(i,mid) == get(i,to)){
                    ans = mid;
                    l = mid  + 1; 
                }else r = mid - 1;
           }
            result[get(i,to)] += ans - to + 1;
            to = ans + 1;
        }
    }
   int q;
    cin >> q;
    while (q--){
        int x;
        cin >> x;
        cout << result[x] << endl;
    }
}