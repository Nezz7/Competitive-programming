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
    //ios_base::sync_with_stdio (0),cin.tie(0);
    int m, n;
    cin >> m >> n;
    int x;
    vector<bool> a;
    for(int i = 0; i < n; i++){
        cout << m << endl;
        fflush(stdout);
        cin >> x;
        if(x == 0){
            return 0;
        }
        a.push_back(x == -1);
    }
    int low = 1, hi = m - 1;
    int id = 0;
    while(low <= hi){
        int mid = (low + hi)/2;
        cout << mid << endl;
        fflush(stdout);
        cin >> x;
        if(x == 0){
            return 0;
        }
        if(!a[id]) {
            x *= -1;
        }
        if(x == -1){
            hi = mid - 1;
        }else low = mid + 1;
        id = (id + 1) % a.size();
    }
}