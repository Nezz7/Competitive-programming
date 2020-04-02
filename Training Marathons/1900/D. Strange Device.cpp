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
int const MAXN = 500 + 9;
int a[MAXN];
int can[MAXN];
int main(){
    memset(a,-1,sizeof (a));
    for(int i = 0; i < MAXN; i++){
        can[i] = 1;
    }
    int n, k;
    cin >> n >> k;
    if ( k  == 1){
        cout << "! "<< k << endl;
        cout.flush();
        return 0;
    }
    set<int> st;

    for(int i = 1; i <= k; i++){
        st.insert(i);
    }
    for(int i = k; i <= n; i++){
        st.insert(i);
        int id, x;
        cout << "? ";
        for(auto cur : st) cout << cur << " ";
        cout.flush();
        cin >> id >> x;
        a[id] = x;
        st.erase(id);
    }
    if (n - k +1 >= k){
        st.clear();
        vector<int> v;
        for(int i = 1; i <= n && v.size() < k; i++){
            if(a[i] != -1){
                v.pb(a[i]);
                st.insert(i);
            }
        }
        sort (all(v));
        cout << "? ";
        for(auto cur : st) cout << cur << " ";
        int id,x;
        cout.flush();
        cin >> id >> x;
        int ans = 0;
        for(int i = 0; i < sz(v); i++){
            ans++;
            if (x == v[i]){
                cout << "! "<< ans << endl;
                cout.flush();
                return 0;
            }
        }
    }
    vector<int> add;
    st.clear();
    for(int i = 1; i <= n; i++){
        if(a[i] == -1) add.push_back(i);
        else st.insert(i);
    }
    int p = 0;
    while (sz(st) < k -1){
        st.insert(add[p]);
        p++;
    }
    bool last = true;
    for (int i = p; i < k - 1 ; i++){
        st.insert(add[i]);
        vector<int> v;
        cout << "? ";
        for(auto cur : st){
            cout << cur << " ";
            if (a[cur] != -1) v.pb(a[cur]);
        }
        cout.flush();
        sort (all(v));
        int id,x;
        cin >> id >> x;
        bool found = false;
        int ans = 0;
        if(x != v[sz(v) - 1]) last = false;
        for(int i = 0; i < sz(v); i++){
            if (x == v[i]){
                found = true;
                break;
            }
            can[i+1] = 0; 
        }
        if (!found){
            for(int i = 0; i < sz(v); i++)
                if ( v[i] > x ){
                    cout << "! "<< i << endl;
                    cout.flush();
                    return 0;      
                }
                cout << "! "<< k << endl; 
                cout.flush();
                return 0;
        }
        st.erase(add[i]);
    }
    if(last){
            cout << "! "<< k << endl;
            cout.flush();
            return 0;
    }
    for(int i = 1; i <= k; i++){
        if (can[i]){
            cout << "! "<< i << endl;
            cout.flush();
            return 0;      
        }
    }
    

}