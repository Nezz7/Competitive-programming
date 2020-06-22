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
int const MAXN = 1e6 + 9;
pair<pair<int,int>,int> a[MAXN];
int b[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i].first.first >> a[i].first.second,a[i].second = i;;
        int ans = -1;
        sort(a, a + n);
        int mx = a[0].first.second;
        for(int i = 0; i < n; i++){
            if(mx >= a[i].first.first){
                mx = max(a[i].first.second,mx);
                continue;
            }
            ans = i;
            break;
            mx = max(a[i].first.second,mx);

        }
        if(ans == -1) cout << -1 << endl;
        else {
            for(int i = 0; i < n; i++){
                if(i < ans) b[a[i].second] = 1;
                else b[a[i].second] = 2; 
            }
            for(int i = 0; i < n; i++) cout << b[i] << ' ';
            cout << endl;
        }
        
    }
}