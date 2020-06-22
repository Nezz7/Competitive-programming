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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int q;
    cin >> q;
    LL ans = 0;
    LL cur = 0;
    vector<LL> v;
    stack<LL> st;
    bool over = false;
    v.pb(0);
    for(int i = 0; i < q; i++){
        string s;
        cin >> s;
        if(s == "add"){
            cur++;
        }
        if(s == "for"){
            LL x;
            cin >> x;
            st.push(x);
            LL last = v[sz(v) - 1];
            v.pop_back();
            v.pb(cur + last);
            cur = 0;
            v.pb(0);
        }
        if(s == "end"){
            LL mul = st.top();
            st.pop();
            LL last = v[sz(v) - 1];
            v.pop_back();
            if(mul * (cur + last) > ((1LL << 32) - 1)) over = true;
            LL x = mul * (cur + last);
            last = v[sz(v) - 1];
            v.pop_back();
            if(x + last > ((1LL << 32) - 1)) over = true;
            v.pb(x + last);
            cur = 0;
        }
    }
    v[0] += cur;
    if(v[0] > ((1LL << 32) - 1)) over = true;
    if(over) cout << "OVERFLOW!!!";
    else cout << v[0] << endl;
}