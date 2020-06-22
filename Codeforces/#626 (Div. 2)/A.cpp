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
        int n;
        cin >> n;
        vector<int> odd;
        vector<int> even;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            if (x % 2) odd.push_back(i+1);
            else even.push_back(i+1);
        }
        if (sz(even)){
            cout << 1 << endl;
            cout << even[0] << endl;
            continue;
        }
        if (sz(odd) >= 2){
            cout << 2 << endl;
            cout << odd[0] << " " << odd[1] << endl;
            continue; 
        }
        cout <<  -1 << endl;
        
    }
}