#include <bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cin >> n;
    double a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a+n);
    reverse(a,a+n);
    double pre[n+1];
    pre[0] = 1;
    for (int i = 0; i < n;i++)
        pre[i + 1] = pre[i] * (1-a[i]);
    double ans = 0;
    for (int i = 0; i < n;i++){
        double cur =0 ;
        for (int j = 0; j <= i; j++){
            if (1-a[j] == 0) cur += pre[i];
            else  cur += (pre[i+1]/(1-a[j]))*a[j];
        }
        ans = max(ans,cur);
    }
    cout <<setprecision(10)<< ans << endl;
}
