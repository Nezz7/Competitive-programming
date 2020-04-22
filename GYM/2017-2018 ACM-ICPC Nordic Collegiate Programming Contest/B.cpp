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
int const MAXN = 500 + 9;
string s[MAXN];
LD a[MAXN],b[MAXN];
int id[MAXN];
bool cmp(int i,int j){
    return b[i] < b[j];
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i] >> a[i] >> b[i];
    LD ans = 1e9;
    vector<int> out;
    for(int i = 0; i < n; i++)
        id[i] = i;
    sort(id,id+n,cmp);
    for(int i = 0; i < n; i++){
        LD cur = a[i];
        int cnt = 1;
        vector<int> v;
        v.pb(i);
        for(int j = 0; j < n && cnt < 4; j++){
            if (id[j] == i) continue;
            cnt++;
            cur += b[id[j]];
            v.pb(id[j]);
        }
        if(cur < ans){
            ans = cur;
            out = v;
        }
    }
    cout << ans << endl;
    for(auto cur : out){
        cout << s[cur] << endl;
    }
}