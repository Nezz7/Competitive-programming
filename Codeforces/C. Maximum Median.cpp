 #include <bits/stdc++.h>
 #define LL long long int
 using namespace std;
 int const MAXN = 2e5+9;
 int a[MAXN];
 int n,k;
 bool ok (LL mid){
    LL ans = 0;
    for (int i = n/2; i < n; i++){
        if (a[i] < mid){
            ans+= mid - a[i];
        }
    }
    return ans <= k;
 }
 int main (){
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >>a[i];
    sort(a,a+n);
    LL low = 0, high = 2e9+1;
    int ans = a[n/2];
    while (low <= high){
        LL mid = (low + high)/2;
        if (ok(mid)){
            ans = mid;
            low = mid + 1;
        }else high = mid - 1;
    }
    cout << ans;

 }
