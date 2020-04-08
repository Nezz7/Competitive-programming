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
    int m, k;
    cin >> m >> k;
    if ( k == 0){
          for (int i = 0; i < (1 << m); i++)
                    cout << i << ' ' << i << ' ';
        return 0;
    }
    bool cond = false;
    int s = 0;
    for (int i = 0; i < (1 << m); i++){
        if( i == k ) continue;
        s ^= i;
    }
    cond = ( s == k );
    if (!cond){
        cout << -1;
        return 0;
    }
    deque<int> dq;
    dq.push_back(k);
    for(int i = 0; i < (1 << m); i++){
        if (i == k) continue;
        dq.push_back(i);
        dq.push_front(i);
    }
    dq.push_front(k);
    for(auto cur : dq) cout << cur << ' ';
}
