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
pair<int,int> last[MAXN];
int sz[MAXN];
priority_queue<pair<double, int>> pq;
void update(int x, int p){
    sz[x]++;
    swap(last[x].first, last[x].second);
    last[x].second = p;
    if(sz[x] == 1) pq.push({-sz[x] * last[x].second, - x});
    if(sz[x] >= 2) pq.push({-sz[x] * (last[x].second + last[x].first) / 2.0, - x});
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++)
        pq.push({0, - i - 1});
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        int nxt = -pq.top().second;
        pq.pop();
        update(nxt, x);
        cout << nxt << " ";
    }
}