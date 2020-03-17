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
    int n,m;
    cin >> n >> m;
    pair<pair<int,int>,int> a[n];
    for (int i = 0; i  < n; i++){
        cin >> a[i] .f . f >> a[i].f . s;
        a[i].f . s *= -1;
        a[i].s= i;
    }
    sort(a,a+n);
    int l = a[0].f.f;
    int r = -a[0].f.s + 1;
    vector<int> out;
    out . push_back(a[0].s + 1);
    int cur = -a[0].f.s;
    int id = 0;
    int j = 20;
    for(int i = 1; i < n && j; i++){
        cout << l << " "<< r<< endl;
        a[i].f . s *= -1;
        if (l <= a[i].f.f && a[i].f.f <= r){
            if (a[i].f.s > cur){
                cur = a[i].f.s;
                id = a[i].s;
            }
        }else{
            cout << id + 1 << endl;
            r = cur + 1;
            out . push_back(id+ 1);
            cur = r;
            i--;
        }
    }
    int i = n-1;
    if(r != m + 1  && l <= a[i].f.f && a[i].f.f <= r){
        r = cur;
        out . push_back(id + 1);
    }
    if (r == m + 1 && l == 1){
        cout << "YES" << endl;
        cout << out.size()<< endl;
        for (auto cur : out) cout << cur << " ";
        return 0;
    }
    cout << "NO";

}