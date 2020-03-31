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
pair<int,int> p[MAXN];
vector<pair<int,int>> d;
void getd(int x){
    for(LL i = 1; i * i <= x; i++){
        if (x % i == 0){
            d.emplace_back(i,x/i);
            d.emplace_back(x/i,i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, a;
    cin >> n >> a;
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }
    getd(a);
    int ans = 0;
    
    if(sz(d) == 2) getd(a-1);
    for(auto cur : d){
        cout << cur.first << ' ' << cur.second << endl;
        int it = 0;
        for(int i = 0; i < n; i++){
            it+=(p[i].first <= cur.first &&  p[i].second <= cur.second);
        }
        ans = max(it,ans);
    }
    cout<< ans;
}