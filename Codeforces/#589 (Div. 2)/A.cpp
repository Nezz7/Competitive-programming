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
 bool cond (int x){
     vector<int> v;
    while (x > 0){
        v.push_back(x%10);
        x/=10;
    }
    sort(all(v));
    for (int i = 0; i < sz(v) - 1; i++){
        if (v[i] == v[i+1]) return false;
    }
    return true;
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int l,r;
    cin >> l >> r;
    for (int i = l; i <= r; i++){
        if (cond(i)){
            cout << i ;
            return 0;
        }
    }
    cout << -1;
 }
