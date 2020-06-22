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
int occ[100];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        string s;
        int n, k;
        cin >> n >> k;
        cin >> s;
        sort(all(s));
        if(k == 1){
            cout << s << endl;
            continue;
        }
        for(int i = 0; i < 30; i++) occ[i] = 0;
        set<int> st;
        for(auto c : s){
            occ[c - 'a']++;
            st.insert(c);
        }
        if(sz(st) == 1){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < (occ[i] + k - 1)/k; j++){
                    char c = i + 'a';
                    cout << c;
                }
            }
            cout << endl;
            continue;
        }
        if (sz(st) == 2){
            int cnt = 0;
            bool cond = false;
            for(int i = 0; i < 26; i++){
                if(occ[i]) cnt++;
                if(occ[i] == k && cnt == 1) cond = true;
            }
            
            if(cond){
                for(int i = 0; i < 26; i++){
                for(int j = 0; j < (occ[i] + k - 1)/k; j++){
                    char c = i + 'a';
                    cout << c;
                }
            }
            cout << endl;
            continue;
            }
        }
        bool ed = false;
        int cnt = 0;
        bool first;
        for(int i = 0; i < 26; i++){
            if(occ[i] && cnt == 0){
                first = (occ[i] < k);
                cnt++;
            }
        }
        cnt = 0;
        if(first)
        for(int i = 0; i < 26; i++){
            if (ed) break;
            if (occ[i]){
                cnt += occ[i];
                if(cnt >=  k){
                     if(!ed){
                        char c = i + 'a';
                        cout << c;
                        ed = true;
                     }
                }
            }
        }
       
        if(!ed) {
            int cnt = 0;
            for(int i = 0; i < 26; i++){
                if(occ[i]){
                    cnt++;
                    if(cnt == 1){
                        occ[i] -= (k - 1);
                    }
                    for(int j = 0; j < occ[i];j++){
                        char c = 'a' + i;
                        cout << c;
                     }
                }
            }
        }
        cout << endl;
    }
}