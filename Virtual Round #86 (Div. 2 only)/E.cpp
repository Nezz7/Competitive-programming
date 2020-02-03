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
 int H , Q;
 long double hei, ti = 0;
 priority_queue<int> p;
 long double nexBad(){
    if (sz(p) == 0) return 1e18;
    return ti + max((long double)0,(hei-p.top())/sz(p));
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> H >> Q;
    vector<pair<int,int>> v;
    for (int i = 0; i < Q; i++){
        int t,h;
        cin >> t >> h;
        v.pb({t,h});
    }
    cout << fixed << setprecision(9);
    sort(all(v));
    hei = H;
    for (auto a : v){
        while(nexBad() < a.f){
            ti = nexBad();
            hei = min(hei,(long double) p.top());
            if (hei == 0){
                cout << ti;
                return 0;
            }
            p.pop();
        }
        hei -= sz(p)*(a.f-ti);
        ti = a.f;
        p.push(a.s);
        while (nexBad() < 1e18){
            ti = nexBad();
            hei = min(hei,(long double) p.top());
            if (hei == 0){
                cout << ti;
                return 0;
            }
            p.pop();
        }
    }

    cout << -1;
 }
