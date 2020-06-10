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
#define Point pair<int,int>
#define F first
#define S second

LD Distance(Point A, Point E) { 
    return sqrt((A.F - E.F) * (A.F - E.F) + (A.S - E.S) * (A.S - E.S));
} 
  
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int x1, y1, x2, y2, a, b;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2 ;
    Point E = {a,b};
    Point A = {x1,y1};
    Point B = {x2,y1};
    Point C = {x1,y2};
    Point D = {x2,y2};
    LD ans = 1e9;
    ans = min(ans,Distance(A,E));
    ans = min(ans,Distance(B,E));
    ans = min(ans,Distance(C,E));
    ans = min(ans,Distance(D,E));
    auto c = minmax(x1,x2);
    auto d = minmax(y1,y2);
    if(c.first <= a && a <= c.second) ans = min(ans,min((LD)abs(b - y1),(LD)abs(b- y2)));
    if(d.first <= b && b <= d.second) ans = min(ans,min((LD)abs(a - x1),(LD)abs(a- x2)));
    cout << fixed;
    cout << setprecision(3) << ans;
}