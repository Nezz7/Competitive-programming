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

 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n;
    cin >> n;
    map<LL,int> mp;
    for (int i = 1; i <= 18; i++){
        LL y = 9;
        LL x = 1;
        LL ret = 0;
        LL p = 1;
        for (int j = 0; j < i - 1; j++){
                p*=10;
            ret += x  * y;
            x++;
            y*=10;
        }
        ret += x;
        mp[p] = ret;
        cout << p << " " << ret << endl;
    }
    for (auto cur : mp) cout << cur.first << " " << cur.second << endl;
    if (n&1) cout << 0;
    else {
    }
 }
