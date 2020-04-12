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
LL a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int mx = -1;
        for (int i = 0; i < n - 1; i++){
            LL d = abs (a[i+1] - a[i]);
            if (a[i+1] >= a[i]) continue;
            if(d == 0) continue;
            int l = -1;
            int r = -1;
            for(int j = 0; j < 60; j++){
                if(d & (1LL << j)){
                    l = j;
                    break;
                }
            }
            for(int j = 60; j >= 0; j--){
                if(d & (1LL << j)){
                    r = j;
                    break;
                }
            }
            if (r > mx) mx = r;
        }
            cout << mx + 1 << endl;
    }
}