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
LL sum [MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        LL occ[26];
        string s;
        cin >> s;
        memset(occ,0,sizeof occ);
        for (int i = 0; i < n + 9; i++) 
            sum[i] = 0;
        for (int i = 0; i < m; i++){
            int x;
            cin >> x;
            sum[0]++;
            sum[x]--;
        }
        for (int i = 1; i < n; i++)
            sum[i] += sum[i-1];
        for (int i = 0; i < n; i++){
            char c = s[i];
            occ[c - 'a']+=sum[i];
            occ[c-'a']++;
        }
        for (auto cur : occ){
            cout << cur << " ";
        }
        cout << endl;

    }
}