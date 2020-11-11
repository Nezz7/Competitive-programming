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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        multiset<int> odd,even;
        vector<pair<int,int>> out;
        for(int i = 2; i <= n; i++){
            if(i & 1) odd.insert(i);
            else even.insert(i);
        }
        int ans = 0;
        for(int i = 0; sz(out) < n - 2 ; i++){
            int add;
            bool goEven = false, goOdd = false;
            if(sz(even) >= 2 && sz(odd) >= 2){
                if(*even.rbegin() >= *odd.rbegin()){
                    goEven = true;
                }else goOdd = true;
            } else if(sz(even) >= 2){
                goEven = true;
            }else if (sz(odd) >= 2){
                goOdd = true;
            }
            if (goEven){
                auto mx = even.find(*even.rbegin());
                auto mn = even.find(*even.rbegin());
                mn--;
                out.emplace_back(*mx,*mn);
                add = (*mn + *mx + 1)/2;
                even.erase(mn);
                even.erase(mx);
            }else if (goOdd){
                auto mx = odd.find(*odd.rbegin());
                auto mn =  odd.find(*odd.rbegin());
                    mn--;
                out.emplace_back(*mx,*mn);
                add = (*mn + *mx + 1)/2;
                odd.erase(mn);
                odd.erase(mx);
            }else {
                int mn = *even.begin();
                int mx = *odd.begin();
                out.emplace_back(mx,mn);
                even.erase(even.begin());
                odd.erase(odd.begin());
                add = (mn + mx + 1)/2;
            }
            if(add & 1){
                if(odd.count(add) == 1){
                    out.emplace_back(add,add);
                }else 
                odd.insert(add);
            }else{
                if(even.count(add) == 1){
                    out.emplace_back(add,add);
                }else 
                    even.insert(add);
            }
        }
          
        
        int x = (odd.size())? *odd.begin() : *even.begin();
        out.emplace_back(x,1);
        ans = (x + 2)/2;
        cout << ans << endl;
        for(auto cur : out){
            cout << cur.first << " " << cur.second << endl;
        }
    }
}