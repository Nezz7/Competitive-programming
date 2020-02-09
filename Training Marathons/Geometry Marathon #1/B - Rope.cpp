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
 LD const PI = acos(-1);
 struct Point {
    LD x,y;
 };
 LD dist (Point a, Point b){
    return  sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, r;
    cin >> n >> r;
    Point a[n];
    Point last;
    LD sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
        if (i == 0) last = a[i];
        else {
            sum += dist(last,a[i]) - 2 * r + PI  * r;
            last = a[i];
        }
    }
    sum+= dist(a[0],a[n-1]) - 2 * r + PI * r ;
    cout << sum;
 }
