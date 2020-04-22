#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const int dx[8] = {0, 0, -1, -1, -1, 1, 1, 1};
const int dy[8] = {-1, 1, 0, 1, -1, 0, 1, -1};
const long double EPS = 1e-14;
const int maxn = 500500;
const int mod = 1e9 + 7;
vector < int > d, rs;
long double dp[maxn];
bool vis[maxn];
long double l, a, b, t, r;
int n;
 
long double solve(int i){
    if(d[i] == l) return 0;
    long double &ret = dp[i];
    if(vis[i]) return ret;
    vis[i] = true;
    ret = (d[i + 1] - d[i]) / a + solve(i + 1);
    long double option1 = 0;
    int idx = upper_bound(all(d), d[i] + t * a + r * b - 1) - d.begin();
    idx = min(idx, n - 1);
    long double dist = d[idx] - d[i];
    long double f = t * a;
    if(f < dist){
        option1 += t;
        dist -= f;
        f = r * b;
        if(f < dist){
            option1 += r;
            dist -= f;
            option1 += dist / a;
        }else{
            option1 += dist / b;
        }
    }else{
        option1 += dist / a;
    }
    option1 += solve(idx);
    ret = min(ret, option1);
    long double option2 = 1e18;
    if(idx > i + 1){
        idx--;
        option2 = 0;
        long double dist = d[idx] - d[i];
        long double f = t * a;
        if(f < dist){
            option2 += t;
            dist -= f;
            f = r * b;
            if(f < dist){
                option2 += r;
                dist -= f;
                option2 += dist / a;
            }else{
                option2 += dist / b;
            }
        }else{
            option2 += dist / a;
        }
        option2 += solve(idx);
        ret = min(ret, option2);
    }
    return ret;
}
 
void track(int i){
    if(d[i] == l) return;
    long double option0 = (d[i + 1] - d[i]) / a + solve(i + 1); 
    long double option1 = 0, option2 = 1e18;
    int idx = upper_bound(all(d), d[i] + t * a + r * b - 1) - d.begin();
    idx = min(idx, n - 1);
    long double dist = d[idx] - d[i];
    long double f = t * a;
    if(f < dist){
        option1 += t;
        dist -= f;
        f = r * b;
        if(f < dist){
            option1 += r;
            dist -= f;
            option1 += dist / a;
        }else{
            option1 += dist / b;
        }
    }else{
        option1 += dist / a;
    }
    option1 += solve(idx);
    if(idx > i + 1){
        idx--;
        option2 = 0;
        long double dist = d[idx] - d[i];
        long double f = t * a;
        if(f < dist){
            option2 += t;
            dist -= f;
            f = r * b;
            if(f < dist){
                option2 += r;
                dist -= f;
                option2 += dist / a;
            }else{
                option2 += dist / b;
            }
        }else{
            option2 += dist / a;
        }
        option2 += solve(idx);
    }
    long double mini = min({option1, option2, option0});
    if(abs(mini - option0) <= EPS){
        track(i + 1);
    }else if(abs(mini - option1) <= EPS){
        rs.push_back(i);
        if(option2 < 1e18) idx++;
        track(idx);
    }else{
        rs.push_back(i);
        track(idx);
    }
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> l >> a >> b >> t >> r;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        d.push_back(x);
    }
    if(d.back() != l) d.push_back(l);
    n = sz(d);
    solve(0);
    track(0);
    cout << sz(rs) << '\n';
    for(auto x : rs) cout << x << ' ';
    cout << '\n';
    return 0;
}