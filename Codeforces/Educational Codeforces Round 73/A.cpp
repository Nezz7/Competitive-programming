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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T; 
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        bool cond = false;
        map<int,int> mp;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            mp[x]++;
        }
        for (auto cur : mp){
            if (mp[2048] > 0) cond = true;
            int x = cur.first;
            int s = cur.second;
            if(s/2)
            mp[x*2] += s/2;
        }
        if (cond) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}