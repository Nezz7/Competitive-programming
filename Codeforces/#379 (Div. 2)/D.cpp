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
vector< pair<int,char> > D1, D2, X, Y;
bool check_d(vector<pair<int,char>> & D1, int x){
    auto nxt = upper_bound(all(D1),make_pair(x,(char)0));
    if(nxt != D1.end()){
        char c = nxt-> second;
        if(c != 'R'){
            return false;
        }
    }
    if(nxt != D1.begin()){
        nxt --;
        char c = nxt-> second;
        if(c != 'R'){
            return false;
        }
    }
    return true;
}
bool check(vector<pair<int,char>> & D1, int x){
    auto nxt = upper_bound(all(D1),make_pair(x,(char)0));
    if(nxt != D1.end()){
        char c = nxt-> second;
        if(c != 'B'){
            return false;
        }
    }
    if(nxt != D1.begin()){
        nxt --;
        char c = nxt-> second;
        if(c != 'B'){
            return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, x, y;
    cin >> n;
    cin >> x >> y;
    int d1 = x + y, d2  = x - y;
    for(int i = 0; i < n; i++){
        char c;
        int a,b;
        cin >> c >> a >> b;
        if(a + b == d1){
            D1.emplace_back(a,c);
        }
        if(a - b == d2){
            D2.emplace_back(a,c);
        }
        if(a == x){
            X.emplace_back(b,c);
        }
        if(b == y){
            Y.emplace_back(a,c);
        }
    }
    sort(all(D1));
    sort(all(D2));
    sort(all(X));
    sort(all(Y));
    bool ans = check_d(D1,x) && check_d(D2,x) && check(X,y) && check(Y,x);
    cout <<((!ans) ? "YES" : "NO")<< endl;

}