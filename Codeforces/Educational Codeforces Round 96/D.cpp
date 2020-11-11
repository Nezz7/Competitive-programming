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
int root[MAXN];
int find (int x){
    if(root[x] == x) return x;
    return root[x] = find(root[x]);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        n = s.size();
        for(int i = 0; i < n; i++){
            root[i] = i;
        }
        root[n] = n;
        set<pair<int,int>> st;
        int cnt = 0, start = 0, ans = 0;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i - 1]) cnt++;
            else {
                if(cnt) st.insert({start, cnt});
                start = i;
                cnt = 0;
            }
        }
        if(cnt) st.insert({start, cnt});

        int x = 100;
        for(int i = 0; i < n && x ; x--,i = find(i)){
            debug(i)
            if(!st.empty() && st.begin()->first < i) st.erase(st.begin());
            if(st.size() == 0){
                cout << i << " skip " << endl;
                ans++;
                i = find(i);
                cout << "go" << " " << i << endl;
                continue;
            }
            pair<int,int> cur = *st.begin();
            cur.second--;
            st.erase(st.begin());
            if(cur.second) st.insert(cur);
            cout << i << "here" << endl;
            root[cur.first] = find(root[cur.first]);
            while(i + 1 < n && s[i] == s[i + 1]) i++;
           //while(find(i) < n && s[i] == s[find(i)]) i = find(i);
            cout << "i =" << i << endl; 
            ans++;
        }
        cout << ans << endl;
        
    }
}