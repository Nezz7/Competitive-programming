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
 int const MAXN = 2e6 + 9;
 struct Point {
    LD x, y;
 };
LL n , r;
LL x[MAXN];
 LD get_y(Point p, LD x){
    LD dx = p.x - x;
    return sqrt(4 * r * r - dx * dx);
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> r;
    for (int i = 0; i  < n; i++) cin >> x[i];
    vector<Point> v;
    for (int i = 0; i < n; i++){
        LD ymax = r;
        for (auto cur : v){
          ymax = max(ymax,get_y(cur,x[i])+cur.y);
        }
        Point p;
        p.x =x[i];
        p.y = ymax;
        v.push_back(p);
    }
    for (auto cur : v)
    cout  << setprecision(20) << cur.y << " ";

 }
