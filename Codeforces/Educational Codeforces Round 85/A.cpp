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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        pair<int,int> a[n];
        bool cond = true;
        for(int i = 0; i < n; i++){
            cin >> a[i].first >> a[i].second;
            if (a[i].first < a[i].second) cond = false;
        }
        for(int i = 1; i < n; i++){
            int x = a[i].first - a[i-1].first;
            if(x < 0) cond = false;
            int y = a[i].second - a[i-1].second;
            if(y < 0) cond = false;
            if(y > x) cond = false;
        }
        cout << ((cond) ? "YES" :"NO") << endl;
        
    }
}