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
int d[MAXN];
int p[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    p[0] = p[1] = 1;
    for (int i = 2; i < 2000; i++){
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0) p[i] = 1;
        } 
    }
    int n;
    cin >> n;
    if (!p[n]){
        cout << n << endl;
        for (int i = 1; i < n; i++){
            cout << i << " " << i + 1 << endl;  
        }
        cout << n << " " << 1 << endl;
        return 0;
    }
    int e  = 0;
    for (int i = n + 1; i < 2000; i++){
        if (!p[i]){
            e = i;
            break;
        }
    }
    vector <pair<int,int>> ans;
     for (int i = 1; i < n; i++){
            ans.emplace_back(i,i+1);
            d[i] ++;
            d[i + 1] ++;
        }
        d[1]++;
        d[n]++;
        ans.emplace_back(1,n);
    for (int i = 1; i <= n && sz(ans) < e ;i++){
        for (int j = i + 2 ; j <= n && sz(ans) < e; j++){
                if ( i == 1 && j == n) continue;
                if ( d[i] == d[j] && d[i] == 2){
                    d[i]++;
                    d[j]++;
                    ans.emplace_back(i,j);
                }
        }
    }
    cout << sz(ans) << endl;
    for ( auto x : ans){
        cout << x.first << " " << x.second << endl;
    }
}