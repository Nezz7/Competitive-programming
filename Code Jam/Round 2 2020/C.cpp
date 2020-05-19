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
int x[MAXN],y[MAXN];
LD norm(int i, int j){
    int y1 = y[i];
    int x1 = x[i];
    int y2 = y[j];
    int x2 = x[j];
    LL x = x1 - x2;
    LL y = y1 - y2;
    return (sqrt(x*x + y*y));
}
bool dot(int i, int j, int a, int b){
    int y1 = y[i];
    int x1 = x[i];
    int y2 = y[j];
    int x2 = x[j];
    LL X = x1 - x2;
    LL Y= y1 - y2;
    int y3 = y[a];
    int x3 = x[a];
    int y4 = y[b];
    int x4 = x[b];
    LL xx = x3 - x4;
    LL yy = y3 - y4;
    LL d = xx * X + Y * yy;
    return ((d + norm(i,j) * norm(a,b))<= 1e-9);
}
pair<int,int>  get (int i, int j){
    int y1 = y[i];
    int x1 = x[i];
    int y2 = y[j];
    int x2 = x[j];
    int a = y2 - y1;
    int b = x2 - x1;
    int g = __gcd(a,b);
    a /= g;
    b /= g;
    return {a,b};
} 

void solve(int t){
    int n;
    cin >> n;
    vector<int> p;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        p.pb(i);
    }
    int ans = 0;
    sort(all(p));
    
    if(n >= 4){
        ans = 4;
        p = {0,1,2,5,6,4,3};
        pair<int,int> s = get(p[1], p[2]);
        cout << s.first << ' ' << s.second << endl;
        for(int i = 3; i < n - 1; i+= 2){
            cout << get(p[i],p[i + 1]).first << ' ' << get(p[i],p[i + 1]).second << endl;
            cout << p[i] << ' ' << p[i + 1] << endl;
            if(get(p[i],p[i + 1]) == s){
                ans = max(min(i + 2,n),ans);
            }else break;
        }
  
    }else ans = n;
    cout << "Case #"<< t <<": " << ans << endl; 
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int cc = 0;
   for(int t = 1; t <= T; t++){
       solve(t);
   }
}