#include <bits/stdc++.h>
using namespace std;
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int L = 0, R = n-1;
    int last = 0;
    int ans = 0;
    string s = "";
    while (L <= R){
        if (last >= a[L] && last >= a[R] ) break;
        if (a[L] == a[R]){
            int mxR = 0;
            int mxL = 0;
            for (int i = R-1; i >= L; i--)
                if (a[i] > a[i+1]) mxR++;
                else break;
            for (int i = L; i < R; i++)
                if (a[i] < a[i+1]) mxL++;
                else break;
            if (mxL >= mxR){
                s += 'L';
                last = a[L];
                L++;
            }else {
                s += 'R';
                last = a[R];
                R--;
            }
            ans++;
            continue;
            }
        if (last < a[L] && last < a[R]){
            if (a[L] <= a [R]){
                s += 'L';
                last = a[L];
                L++;
            }else {
                s += 'R';
                last = a[R];
                R--;
            }
        }else if (last < a[L]){
                s += 'L';
                last = a[L];
                L++;
        }else {
                s += 'R';
                last = a[R];
                R--;
        }
        ans++;
    }
    cout << ans << "\n" << s;

}
