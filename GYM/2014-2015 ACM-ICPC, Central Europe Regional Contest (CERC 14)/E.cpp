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
int l, r;
deque<int> dq;
void print(){
    for(auto x : dq) cout << x << ' ';
    cout << endl;
}
void add_left(int x){
    dq.push_front(x);
     if(sz(dq) >= 2){
        if(dq[0] == dq[1]){
            int cnt = 2*dq[0];
            dq.pop_front();
            dq.pop_front();
            add_left(cnt);
        }
    }
}
void add_right(int x){
    dq.push_back(x);
    int n = sz(dq);
    if(n >= 2){
        if(dq[n - 1] == dq[n - 2]){
            int cnt = 2*dq[n - 1];
            dq.pop_back();
            dq.pop_back();
            add_right(cnt);
        }
    }
}


int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        l = -1, r = -1;
        string ans = "";
        int x;
        dq.clear();
        bool cond = true;
        for(int i = 0; i < n; i++){
            cin >> x;
            if(sz(dq) < 2){
                ans+= "l";
                add_left(x);
            }else {
                int sz = sz(dq);
                l = dq[0];
                r = dq[sz - 1];
                if(x == r) add_right(x),ans+="r";
                else if(x == l) add_left(x),ans+="l";
                else if(l < x && r < x) cond = false;
                else if(l < x && r > x) add_right(x),ans+="r";
                else if( r < x && l > x) add_left(x),ans+="l";
                else if( r < l ) add_right(x),ans+="r";
                else add_left(x),ans+="l";
            }
        }
        if(sz(dq) != 1) cond = false;
        if(cond) cout << ans << endl;
        else cout << "no" << endl;
    }

}