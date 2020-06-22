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
int l[MAXN];
int h[MAXN];
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int last = 0;
    LL ans = 0;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        ans += a[i]/2;
        if (a[i]%2 && last) ans++,last = 0;
        else last = a[i]%2;
    }
    LL ans2 = 0;

    for (int i = 0; i < n-1;i++){
        ans2+= (a[i]/2);
        if (a[i]%2 && l[i] + 1 <= a[i+1]){
            if (a[i+1]%2) a[i+1]--,ans2++;
            else{
                if (!l[i]) l[i+1]++;
                ans2++,a[i+1]--;
            }
        }
    }
    ans2+=(a[n-1]/2);
    cout << max(ans,ans2) << endl;
 }
