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
int a[MAXN],b[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    stack<int> q;
    set<int> st;
    for(int i = 0; i < n + 9; i++){
        st.insert(i);
    }
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cur = 0;
    for(int i = 0; i < n; i++){
        q.push(i);
        if(a[i] == cur){
            continue;
        }
        while(!q.empty()){
            int x = q.top();
            q.pop();
            b[x] = cur;
            cur++;
            if(cur == a[i]) break;
        }
        if(cur != a[i]){
            cout << -1;
            return 0;
        }
    }
    while(!q.empty()){
        int x = q.top();
        q.pop();
        b[x] = 1e6;
    }
    for(int i = 0; i < n; i++){
        st.erase(b[i]);
        int x = *st.begin();
        if(x != a[i]){
            cout << -1 << endl;
            return 0;
        }

    }
    for(int i = 0; i < n; i++) cout << b[i] << ' ';
}