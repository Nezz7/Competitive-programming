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
 int a [] = {0,0,0,0,0,1,0,1,2};
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,p,t;
    cin >> n >> p >> t;
    p--;
    int x = (t/9) * 3 + a[t%9];
    if (p < x  or x + n <= p) cout << -1;
    else cout << (p - x) + 1;
 }
