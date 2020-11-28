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
int b[MAXN], a[MAXN];
vector<vector<int>> out;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int j = 0; j < m; j++){
        cin >> b[j];
    }
    int idx_a = 0, idx_b = 0;
    int cur = 0;
    for(int i = 0; i < n; i++){
        if(cur == 0){
            while( idx_b < m && b[idx_b] < a[i]) idx_b++;
            out.emplace_back();
            out.back().push_back(i + 1);
            cur = 1;
            idx_b++;
        }else {
            if(b[idx_b] < a[i] or cur == k){
                out.emplace_back();
                out.back().push_back(i + 1);
                while( idx_b < m && b[idx_b] < a[i]) idx_b++;
                cur = 1;
            }else {
                out.back().push_back(i + 1); 
                cur++;
            }
            idx_b++;
        }
    }
    cout << sz(out) << endl;
    for(auto cur : out){
        cout << sz(cur) << " ";
        for(auto x : cur) cout << x << " ";
        cout << endl;
    }
}