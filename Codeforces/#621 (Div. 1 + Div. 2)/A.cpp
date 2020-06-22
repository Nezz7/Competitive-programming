#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n, d;
        cin >> n >> d;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int i = 1;
        while (i < n && d){
            if (a[i] == 0) i++;
            else{
                if (i <= d) d-=i, a[0]++,a[i]--;
                else break;
            }
        }
        cout << a[0] << endl;
    }
}