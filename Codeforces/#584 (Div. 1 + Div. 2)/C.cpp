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
int ans[MAXN];
int L[15],R[15];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) ans[i] = -1;
        for(int i = 0; i < 10; i++) L[i] = R[i] = -1;
        string a;
        cin >> a;
        for(auto &c : a) c -= '0';
        for(int i = 0; i < n; i++){
            int x = a[i];
            if(L[x] == -1) L[x] = i;
            R[x] = i;
        }
        int last = -1;
        int cur = 0;
        for(int i = 0; i < 10; i++){
            if(L[i] != -1){
                if(last <= L[i]){
                    last = R[i];
                    for(int j = 0; j < n; j++){
                        if(a[j] == i) ans[j] = 1;
                    }
                }else {
                    for(int j = last; j < n; j++){
                        if(a[j] == i) ans[j] = 1;
                    }
                    cur = i;
                    break;
                }
            }            
        }
        last = -1;
        bool cond = true;
        for(int i = cur; i < 10; i++){
            if(L[i] != -1){
                if(last <= L[i]){
                    for(int j = L[i]; j < n; j++){
                        if(a[j] == i && ans[j] == -1) ans[j] = 2,last = j;
                    }
                }else cond = false;
            }
            
        }
        for(int i = 0; i < n; i++){
            if(ans[i] == -1) cond = false;
        }
        if(!cond){
            cout << "-" << endl;
            continue;
        }
        for(int i = 0; i < n; i++) cout << ans[i];
        cout << endl;
    }
}