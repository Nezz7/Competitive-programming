 #include <bits/stdc++.h>
 #define f first
 #define s second
 #define endl '\n'
 #define LL long long
 #define pb push_back
 #define sz(a) (int)a.size()
 #define all(a) a.begin(),a.end()
 #define rall(a) a.rbegin(),a.rend()
 #define debug(x) cerr << #x << " is " << x << endl;
 using namespace std;
 int const MAXN = 2e6 + 9;
 struct Point {
    LL x,y,id;
 };
 bool collinear (Point a, Point b, Point c){
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) == 0;
 }
 bool cmp (Point a, Point b){
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    Point a[n];
    Point pmx, pmn;
    int ind1 = 0, ind2 = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
        a[i].id = i+1;
    }
    sort(a,a+n,cmp);
    pmx = a[n-1];
    pmn = a[0];
    int ans = 0;
    for (int i = 0; i < n ; i++){
       if (col(pmx,a[i],pmn)) ans++;
    }
    cout << (ans == n) << endl;
    if (ans == n){
        cout << pmx.id << " " << pmn.id << endl;
    }
 }
