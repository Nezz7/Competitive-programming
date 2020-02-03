#include <bits/stdc++.h>
using namespace std;
int main (){
    string s;
    cin >> s;
    int n = s.size();
    int a[n+2],b[n+2];
    a[0] = b[0] = 0;
    for (int i = 0; i < n;i++){
        a[i + 1] = (s[i]=='a') + a[i];
        b[i + 1] = (s[i]=='b') + b[i];
    }
    int ans = 1;
    for (int i = 0; i < n;i++){
        for (int j = i+1; j < n; j++){
            int cur = a[i+1]+b[j+1]-b[i]+a[n]-a[j];
            ans = max(cur,ans);
        }
    }
    cout << ans << "\n";


}
