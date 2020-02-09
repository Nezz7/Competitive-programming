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
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    LL ans = 0;
    priority_queue<LL> pq;
    for (int i = 0; i < n; i++){
        LL x;
        cin >> x;
        pq.push(-x);
    }
    if (n % 2 == 0){
        LL mn = pq.top();
        pq.pop();
        LL mn2 = pq.top();
        pq.pop();
        ans+= (-mn) + (-mn2);
        pq.push(mn + mn2);
    }
    while (pq.size()>= 3){
        LL mn = -pq.top();pq.pop();
        LL mn1 = -pq.top();pq.pop();
        LL mn2 = -pq.top();pq.pop();
        ans += (mn + mn1 + mn2);
        pq.push( -mn - mn1 - mn2);
    }
    cout << ans;
 }
