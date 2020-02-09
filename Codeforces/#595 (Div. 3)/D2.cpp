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
 int a[MAXN];
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n , k ;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int l ,r;
        cin >> l >> r;
        a[l]++;
        a[r+1]--;
    }
    for(int i = 1; i < MAXN; i++){
        a[i]+=a[i-1];
        if (a[i]> k) cout << i << endl;
    }
 }
