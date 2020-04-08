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
map<LL,int> mp;
LL l[MAXN],r[MAXN];
LL sl[MAXN],sr[MAXN];
LL get(LL x){
    return x * (x + 1)/2;
}
vector<pair<int,int>> p;
vector<pair<int,int>> a;
vector<int> ans[MAXN];
void gen(){
    for (auto cur : p){
        int s = cur.first;
        int len = cur.second;
        for(int i = 0; i < len; i++){
            for (int x = s + i; x < s + len * 2; x+= 2)
                ans[i].pb(x + 1);
        }
    }
    for(auto cur : a){

    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,k;
    cin >> n >> k;
    string s;
    cin  >> s;
    for (int i = 0; i < n; i++){
        if (s[i] == 'L') r[i + 1] = 0, l[i + 1] = l[i] + 1;
        else l[i+1] = 0, r[i + 1] = r[i] + 1;
    }
    for (int i =n - 1; i >= 0; i--){
        if (s[i] == 'L') sr[i + 1] = 0, sl[i + 1] = sl[i + 2] + 1;
        else sl[i + 1] = 0, sr[i + 1] = sr[i + 2] + 1;
    }

    LL ans = 0;
    for (int i = 0; i < n; i++){
        int j = i;
        int cur = 0;
        while(j + 1< n && s[j] == 'L' && s[j+1] == 'R'){
            cur++;
            debug(j)
            j+=2;
        }
        p.emplace_back(i,cur);
        cout << j << endl;
        if (j < n && s[j] == 'R'){
            a.emplace_back(-cur,j + sr[j+2]);
            ans += sr[j+ 1];
        }
        if(i - 1 >= 0 && s[i-1] == 'L'){
            a.emplace_back(cur, i - l[i]);
            ans += l[i+1];
        }
        i = j;
        ans+= cur;
    }
    if (ans != k){
        cout << -1 << endl;
    }
}