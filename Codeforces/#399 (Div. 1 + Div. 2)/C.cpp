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
map<vector<int>,int> mp;
map<int,vector<int>> id;

int x;
int tim = 1;
void go(vector<int> & v, int k){
    if(k == 0){
        cout << v[sz(v) - 1] << " " << v[0] << endl;
        return;
    }
    for(int i = 0; i < sz(v); i+= 2) v[i] ^= x; 
    sort(all(v));
    if(mp.count(v)){
        int s = mp[v];
        int cycle = tim - s;
        k--;
        k %= cycle;
        s += k;
        vector<int> ret = id[s];
        cout << ret[sz(v) - 1] << " " << ret[0] << endl;    
        return ;
    }
    id[tim] = v;
    mp[v] = tim ++;
    go(v,k - 1);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, k;
    cin >> n >> k >> x;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.pb(a);
    }
    sort(all(v));
    go(v,k);
}