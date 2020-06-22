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
int ans[8];
int main(){
    set<int> st; 
    st.insert(4);
    st.insert(8);
    st.insert(15);
    st.insert(16);
    st.insert(23);
    st.insert(42);
    int n, a1, b1, a2, b2;
    cout << "? 1 3" << endl;
    cout << flush;
    cin >> n;
    for(auto x : st){
        for(auto y : st){
            if(x * y == n){
                a1 = x;
                b1 = y;
            }
        }
    }
    cout << "? 2 3" << endl;
    cout << flush;
    cin >> n;
    for(auto x : st){
        for(auto y : st){
            if(x * y == n){
                a2 = x;
                b2 = y;
            }
        }
    }
    if(a1 == a2){
        ans[0] = b1;
        ans[1] = b2;
        ans[2] = a1;
    }else if(a1 == b2){
        ans[0] = b1;
        ans[1] = a2;
        ans[2] = a1;
    }else if(b1 == a2){
        ans[0] = a1;
        ans[1] = b2;
        ans[2] = b1;
    }else {
        ans[0] = a1;
        ans[1] = a2;
        ans[2] = b1;
    }
     cout << "? 4 6" << endl;
     cout << flush;
    cin >> n;
    for(auto x : st){
        for(auto y : st){
            if(x * y == n){
                a1 = x;
                b1 = y;
            }
        }
    }
    cout << "? 5 6" << endl;
    cout << flush;;
    cin >> n;
    for(auto x : st){
        for(auto y : st){
            if(x * y == n){
                a2 = x;
                b2 = y;
            }
        }
    }
    if(a1 == a2){
        ans[3] = b1;
        ans[4] = b2;
        ans[5] = a1;
    }else if(a1 == b2){
        ans[3] = b1;
        ans[4] = a2;
        ans[5] = a1;
    }else if(b1 == a2){
        ans[3] = a1;
        ans[4] = b2;
        ans[5] = b1;
    }else {
        ans[3] = a1;
        ans[4] = a2;
        ans[5] = b1;
    }
    cout << "! " ;
    for(int i = 0; i < 6; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
    cout << flush;

}