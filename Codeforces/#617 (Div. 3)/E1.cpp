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
int a[MAXN];
vector<int> g[26];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool cond = true;
    vector<int> v;
    for (int i = 0; i < n; i++){
        g[s[i] - 'a'].push_back(i);
    }
    int j = 0;
    for (int i = 0; i < 26; i++){
        for (int c = 0; c <  sz(g[i]); c++){
            int cur = g[i][c];
            if (cur >= j){
                while (j < cur){
                    a[j] = 0;
                    j++;
                }
                a[cur] = 1;
                j = cur + 1;
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (a[i] == 0){
            v.push_back(i);
        }
    }
    for (int i = 0; i < sz(v) - 1; i++){
        if (s[v[i]] > s[v[i+1]]) cond = false;
    }
    if (cond){
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) 
            cout << a[i] ;
    }else cout << "NO" << endl;
}