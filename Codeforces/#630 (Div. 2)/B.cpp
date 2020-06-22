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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int cnt = 0;
        map<int,int> mp;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            for(int j = 2; j * j <= x; j++){
                if(x % j == 0){
                    if(mp.count(j)) {
                        a[i] = mp[j];
                        break;
                    }else {
                        a[i] = ++cnt;
                        mp[j] = cnt;
                        break;
                    }
                }
            }
        }
        cout << cnt << endl;
        for(int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << endl;
    }
}