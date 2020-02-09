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
int d [50];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        for (int j = 0; j < 31; j++){
            if (a[i] & (1 << j)) d[j]++;
        }
    }
    int c = (1 << 0);
    for (int i = 31; i >= 0; i--){
        if (d[i] == 1){
            c = (1 << i);
            break;
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
        if (a[i] & c){
            mx = a[i];
            break;
        }
    map<int,int> mp;
    for (int i= 0; i < n; i++) mp[a[i]]++;
    mp[mx] --;
    vector<int> v1;
    vector<int> v2;
    v1.pb(mx);
    for (auto cur : mp){
        int x = cur.first;
        int y = cur.second;
        if (mx & x == 0){
            for (int i = 0; i < y; i++) v1.pb(x);
        }else for (int i = 0; i < y; i++) v2.pb(x);
    }
    for (auto cur : v1) cout << cur << " ";
    for (auto cur : v2) cout << cur << " ";
}