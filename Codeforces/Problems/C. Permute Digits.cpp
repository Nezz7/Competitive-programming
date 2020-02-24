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
string a,b;
int solve (int pos, vector<int> occ, string ss, bool cond){
    if (pos == b.size()) {cout << ss << endl; return 1;}
    int lim;
    if (cond) lim = 9;
    else lim = b[pos] - '0';
    for (int i = lim; i >= 0; i--){
        if (occ[i]){
            vector<int> v = occ;
            v[i] --;
            int f = cond;
            if (i < b[pos] -'0') f= 1;
            string c = ss;
            if (i or c.size()) c = ss + (char) (i + '0');
            if (solve(pos+1,v,c,f)) return 1;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> a >> b;
    if(sz(a) < sz(b)){
        sort(rall(a));
        cout << a << endl;
        return 0;
    }
    vector<int>occ (10,0);
    for (auto cur : a){
        occ[cur - '0'] ++;
    }
    string c ="";
    solve(0,occ,c,0);
    
}