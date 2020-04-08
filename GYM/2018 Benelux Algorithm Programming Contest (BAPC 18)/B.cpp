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
int month[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int month2[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int getDay(string s){
    for(auto &c : s) c-='0';
    int m = s[0] * 10 + s[1];
    int d = s[3]*10 + s[4];
    return month [m - 1] + d;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    set<int> st;
    for(int i = 1; i <= 12; i++){
        month[i] += month[i-1];
    }
    for (int i = 0; i < n; i++){
        string a,b;
        cin >> a >> b;
        st.insert(getDay(b));
    }
    int mx = 0;
    for(int i = 1; i <= 365; i++){
        if (st .count(i)) continue;
         auto it = st.lower_bound(i);
         int last = 0;
         int cur = 0;
        if (it == st.begin()) {
            last = *(st.rbegin());
            cur = 365 - last + i;
        }else{
            it--,last = *it;
            cur = i - last;
        } 
        mx = max(cur, mx);
    }
    
    for (int i = 10; i <= 12; i++){
        int start = 1;
        if ( i == 10) start = 28;
        else start = 1;
        for (int j = start ; j <= month2[i]; j++){ 
            int d = month[i - 1] + j;  
            if (st .count(d)) continue;
            auto it = st.lower_bound(d);
            int last = 0;
            int cur = 0;
            if (it == st.begin()) {
                last = *(st.rbegin());
                cur = 365 - last + d;
            }else{
                it--,last = *it;
                cur = d - last;
            } 
            if (mx == cur){
                cout << i / 10 << i % 10  << '-' << j / 10 << j % 10;
                return 0;
            }
        }
    }
    for (int i = 1; i <= 12; i++){
        for (int j = 1; j <= month2[i]; j++){ 
            int d = month[i - 1] + j;  
            if (st .count(d)) continue;
            auto it = st.lower_bound(d);
            int last = 0;
            int cur = 0;
            if (it == st.begin()) {
                last = *(st.rbegin());
                cur = 365 - last + d;
            }else{
                it--,last = *it;
                cur = d - last;
            } 
            if (mx == cur){
                cout << i / 10 << i % 10  << '-' << j / 10 << j % 10;
                return 0;
            }
        }
    }
}