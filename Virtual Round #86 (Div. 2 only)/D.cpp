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
 bool eq (double x, double y){
    return abs(x-y) < 1e-6;
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    double h;
    int n;
    cin >> h >> n;
    bool cond = false;
    pair<double,double> a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        if (a[i].second == 0) cond = true;
    }
    if (cond == false ){
        cout << -1;
        return 0;
    }
    sort (a,a+n);
    priority_queue<double> pq;

    double t = 0;
    double s = 0;
    for (int i = 0; i < n ; i++){
        if (a[i].second <  h){
            t = a[i].first;
            pq.push(a[i].second);
            s++;
        }
        double top = pq.top();
        if (pq.empty()) top = 0;
        cout << " -----------" << endl;
        debug(h)
        debug(t)
        debug(s)
        debug(top)
        cout << endl ;
        if (i+1 < n){
           double dif = a[i+1].first - t;
            double x;
            if (s == 0) {
                t = a[i+1].first;
                continue;
            }
            else x = (h-top)/s;
            debug(dif)
            debug (x)
            if (eq(dif,x)){
                    t = a[i+1].first;
                    h = top;
                    while (!pq.empty() && pq.top() == top)
                        pq.pop(),s--;
            }else  if (dif < x){
                t = a[i+1].first;
                h -= s * dif;
            }else if (dif > x){
                t+= x;
                h = top;
                while (!pq.empty() && pq.top() == top)
                    pq.pop(),s--;
                i--;
            }
            debug(i)
        }else {
                cout << "last" << endl;
                 while (!pq.empty()){
                        double top = pq.top();
                        double x = (h-top)/s;
                        t+=x;
                        h = top;
                        debug(h)
                        debug(t)
                        while (!pq.empty() && pq.top() == top)
                            pq.pop(),s--;
                 }
            }
        }
        cout<<setprecision(20) << t;
 }
