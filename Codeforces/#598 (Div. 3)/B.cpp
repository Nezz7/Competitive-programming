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
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int cur = 0;
        while (cur < n){
            int mn = cur;
            for(int i = cur; i < n; i++){
                if(a[mn] > a[i]){
                    mn = i;
                }
            }
            int x = a[mn];
            for(int i = mn; i > cur; i--){
                a[i] = a[i - 1];
            }
            a[cur] = x;
            if(cur == mn) cur++;
            else cur = mn;
        }
        for(int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << endl;
    }
}