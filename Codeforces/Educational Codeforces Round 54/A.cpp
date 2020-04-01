#include <bits/stdc++.h>
#define f first
#define s second
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = -1;
    for(int i = 0; i < n - 1; i++)
        if (s[i] > s[i+1] && x == -1) x = i;
    if (x == -1) x = n - 1;
    for(int i = 0; i < n; i++)
        if(i == x) continue;
        else cout << s[i];
}